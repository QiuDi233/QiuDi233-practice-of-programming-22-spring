/*����
����һ����ά���飺

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�



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
			if (!visit[x1][y1]&&maze[x1][y1]==0&&x1>=0&&y1>=0&&x1<5&&y1<5) {//ע��Ҫ�ж��Ƿ����Թ��� ��Ȼ������ܶ����Ľڵ� �����Խ��
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
