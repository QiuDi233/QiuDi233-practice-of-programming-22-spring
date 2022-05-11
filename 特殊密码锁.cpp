/*描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
011
000
样例输出
1*/

#include<iostream>
using namespace std;
int now[35];
int now2[35];
int goal[35];
int n = 0;
int ans = 100;
void push(int i) {//按下第i个按钮
	if (i == 0) {
		now[i] = 1 - now[i];
		now[i + 1] = 1 - now[i + 1];
		return;
	}
	if (i == n - 1) {
		now[i] = 1 - now[i];
		now[i - 1] = 1 - now[i - 1];
		return;
	}
	now[i - 1] = 1 - now[i - 1];
	now[i] = 1 - now[i];
	now[i + 1] = 1 - now[i + 1];
	return;
}
void push2(int i) {//按下第i个按钮
	if (i == 0) {
		now2[i] = 1 - now2[i];
		now2[i + 1] = 1 - now2[i + 1];
		return;
	}
	if (i == n - 1) {
		now2[i] = 1 - now2[i];
		now2[i - 1] = 1 - now2[i - 1];
		return;
	}
	now2[i - 1] = 1 - now2[i - 1];
	now2[i] = 1 - now2[i];
	now2[i + 1] = 1 - now2[i + 1];
	return;
}
bool check() {
	for (int i = 0; i < n; ++i) {
		if (now[i] != goal[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int lock[100];
	char ch;
	int p = 0;
	while (cin >> ch) {
		lock[p++] = ch-'0';
	}
	
	for (int i = 0; i < p / 2; ++i) {
		now[i] = lock[i];
		now2[i] = lock[i];
	}
	for (int i = 0; i < p / 2; ++i) {
		goal[i] = lock[i + p / 2];
	}
	n = p / 2;
	
	//枚举最左边的灯按不按 然后剩下的怎么按就可以确定了
	push(0);//按的话
	int cnt1 = 1;
	for (int i = 1; i < n; ++i) {
		if (now[i - 1] != goal[i - 1]) {
			push(i);
			cnt1++;
		}
	}
	if (now[n - 1] == goal[n - 1]) {
		ans = cnt1;
	}

	//不按的话
	cnt1 = 0;
	for (int i = 1; i < n; ++i) {
		if (now2[i - 1] != goal[i - 1]) {
			push2(i);
			cnt1++;
		}
	}
	if (now2[n - 1] == goal[n - 1]) {
		if (cnt1 < ans)
			ans = cnt1;
	}

	if (ans == 100) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
