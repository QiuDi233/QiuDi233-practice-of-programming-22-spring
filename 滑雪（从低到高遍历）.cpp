/*����
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������Ļ��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
����
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
���
��������ĳ��ȡ�
��������
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
�������
25*/

#include<iostream>
#include<algorithm>
using namespace std;
struct ice {
	int h;
	int i;
	int j;
	bool operator< (ice b) {
		return h < b.h;
	}
}arr[10010];
int main() {
	int R = 0, C = 0;
	cin >> R >> C;
	int snow[105][105];
	int p = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> snow[i][j];
			arr[p].h = snow[i][j];
			arr[p].i = i;
			arr[p].j = j;
			p++;
		}
	}
	int road[105][105];//��ʾ�����snow[i][j]���·
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			road[i][j] = 1;
		}
	}
	sort(arr, arr + p);//���߶ȴ�С��������
	for (int k = 0; k < p; ++k) {
		int ii = arr[k].i;
		int jj = arr[k].j;
		int maxx = 1;
		if (ii > 0&&snow[ii][jj] > snow[ii - 1][jj] ) {
			maxx = max(maxx, road[ii - 1][jj] + 1);
		}
		if (ii+1<R&&snow[ii][jj] > snow[ii + 1][jj]) {
			maxx = max(maxx, road[ii + 1][jj] + 1);
		}
		if (jj>0&& snow[ii][jj] > snow[ii][jj-1]) {
			maxx = max(maxx, road[ii][jj-1] + 1);
		}
		if (jj+1<C&&snow[ii][jj] > snow[ii][jj+1]) {
			maxx = max(maxx, road[ii][jj+1] + 1);
		}
		road[ii][jj] =maxx;
	}
	int M = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			M = max(M, road[i][j]);
		}
	}
	cout << M << endl;
	return 0;
}
