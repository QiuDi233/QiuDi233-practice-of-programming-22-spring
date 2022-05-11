/*描述
我的生日要到了！根据习俗，我需要将一些派分给大家。我有N个不同口味、不同大小的派。有F个朋友会来参加我的派对，每个人会拿到一块派（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。

我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。因此所有人拿到的派是同样大小的（但不需要是同样形状的），虽然这样有些派会被浪费，但总比搞砸整个派对好。当然，我也要给自己留一块，而这一块也要和其他人的同样大小。

请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。

输入
第一行包含两个正整数N和F，1 ≤ N, F ≤ 10 000，表示派的数量和朋友的数量。
第二行包含N个1到10000之间的整数，表示每个派的半径。
输出
输出每个人能得到的最大的派的体积，精确到小数点后三位。
样例输入
3 3
4 3 3
样例输出
25.133*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
int n = 0, f = 0;
double v[10005];
bool cake(double x) {
	//是否可以每人分到体积为x的蛋糕
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += int(v[i] / x);
	}
	return cnt >= (f+1);
}
int main() {
	int r[10005];
	cin >> n >> f;
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	double left = 0;
	double right = 100000000;
	for (int i = 0; i < n; ++i) {
		v[i] = PI * r[i] * r[i];
		if (v[i] > right) {
			right = v[i];
		}
	}
	
	double mid = (left + right) / 2;//每个朋友可以分到的蛋糕体积
	while (right-left>1e-6) {
		mid = (left + right) / 2;
		if (cake(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << fixed << setprecision(3) << mid << endl;
	return 0;
}
