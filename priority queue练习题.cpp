/*描述
我们定义一个正整数a比正整数b优先的含义是：
*a的质因数数目（不包括自身）比b的质因数数目多；
*当两者质因数数目相等时，数值较大者优先级高。


现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。

输入
第一行: num (添加元素次数，num <= 30)

下面10*num行，每行一个正整数n（n < 10000000).

输出
每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。

样例输入
1
10 7 66 4 5 30 91 100 8 9
样例输出
66 5*/


#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
bool is_prime(int n) {
	if (n == 2)
		return true;
	if (n == 1)
		return false;
	for (int i = 2; i < sqrt(n) + 1; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int prime_num(int a) {
	int cnt = 0;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a % i == 0) {//如果i是a的因数
			int tmp = a / i;//则a/i也是它的因数
			if (is_prime(i))
				cnt++;
			if (is_prime(tmp) && tmp != i)
				cnt++;

		}
	}
	return cnt;
}
struct cmp1 {
	bool operator()(int num1, int num2) {
		if (prime_num(num1) == prime_num(num2)) {
			return num1 > num2;
		}
		return prime_num(num1) > prime_num(num2);
	}
};
struct cmp2 {
	bool operator()(int num1, int num2) {
		if (prime_num(num1) == prime_num(num2)) {
			return num1 < num2;
		}
		return prime_num(num1) < prime_num(num2);
	}
};
int main() {
	priority_queue<int, vector<int>, cmp2>q1;
	priority_queue<int, vector<int>, cmp1>q2;
	int num = 0;
	int n = 0;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> n;
			q1.push(n);
		}
		cout << q1.top() <<" ";
		q1.pop();
		int tmp = 0;
		while (!q1.empty()) {//把q1中的元素转到q2中
			tmp = q1.top();
			q2.push(tmp);
			q1.pop();
		}
		cout << q2.top() << endl;
		q2.pop();
		while (!q2.empty()) {//再转回来
			tmp = q2.top();
			q1.push(tmp);
			q2.pop();
		}
	}
	return 0;
}