/*描述
定义一个二维数组：

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，
要求编程序找出从左上角到右下角的最短路线。



输入
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
输出
左上角到右下角的最短路径，格式如样例所示。
样例输入
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
样例输出
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)*/

#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int maze[10][10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct node {
	int x;
	int y;
}ans[50];
int min_len = 100;
node tmp[50];
bool visit[50][50];
void replace(int len) {
	min_len = len;
	for (int i = 0; i < len; ++i) {
		ans[i] = tmp[i];
	}
}
void dfs(int x, int y, int len) {
	if (x == 4 && y == 4) {//到了 
		if (len < min_len) {
			replace(len);
		}
	}
	for (int i = 0; i < 4; ++i) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (maze[xx][yy]||xx<0||yy<0||xx>=5||yy>=5||visit[xx][yy])
			continue;
		tmp[len].x = xx;
		tmp[len].y = yy;
		visit[xx][yy] = true;
		dfs(xx, yy, len + 1);
		visit[xx][yy] = false;
	}
}
int main() {

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> maze[i][j];
		}
	}
	memset(visit, 0, sizeof(visit));
	visit[0][0] = true;
	dfs(0, 0, 0);
	cout << "(0, 0)" << endl;
	for (int i = 0; i < min_len; ++i) {
		cout << "(" << ans[i].x << ", " << ans[i].y << ")" << endl;
	}
	return 0;
}

