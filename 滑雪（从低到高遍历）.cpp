/*描述
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
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
	int road[105][105];//表示起点是snow[i][j]的最长路
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			road[i][j] = 1;
		}
	}
	sort(arr, arr + p);//按高度从小到大排序
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
