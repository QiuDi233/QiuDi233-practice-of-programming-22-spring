/*描述
定义一个二维数组：

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。



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
#include<cstring>
using namespace std;
struct node {
	int r;
	int c;
	int f;
	node() {
		r = 0;
		c = 0;
		f = -1;
	}
	node(int rr,int cc,int ff):r(rr),c(cc),f(ff){}
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[5][5];
node q[30];
void output(int now) {
	if (now == -1) {
		return;
	}
	output(q[now].f);
	cout << "(" << q[now].r << ", " << q[now].c << ")" << endl;
}
int main() {
	int maze[6][6];
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> maze[i][j];  
	
	int head=0;
	int tail=0;
	q[tail] = node(0, 0,-1);
	visit[0][0] = true;
	tail++;
	bool f = false;
	while (head != tail) {
		for (int i = 0; i < 4; i++) {
			int x1 = q[head].r + dx[i];
			int y1 = q[head].c + dy[i];
			if (!visit[x1][y1]&&maze[x1][y1]==0&&x1>=0&&y1>=0&&x1<5&&y1<5) {//注意要判断是否还在迷宫内 不然延申出很多出界的节点 数组会越界
				q[tail] = node(x1, y1, head);
				if (q[tail].r == 4 && q[tail].c == 4)
				{
					f = true;
					break;
				}
				visit[q[head].r + dx[i]][q[head].c + dy[i]] = true;
				tail++;
			}
		}
		if (f)
			break;
		head++;
	}
	output(tail);

	return 0;
}
