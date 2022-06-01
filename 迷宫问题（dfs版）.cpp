/*����
����һ����ά���飺

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�
Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�



����
һ��5 �� 5�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ�⡣
���
���Ͻǵ����½ǵ����·������ʽ��������ʾ��
��������
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
�������
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
	if (x == 4 && y == 4) {//���� 
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

