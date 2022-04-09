/*����
���Ƕ���һ��������a��������b���ȵĺ����ǣ�
*a����������Ŀ��������������b����������Ŀ�ࣻ
*��������������Ŀ���ʱ����ֵ�ϴ������ȼ��ߡ�


���ڸ���һ����������ʼԪ����ĿΪ0��֮��ÿ�����������10��Ԫ�أ�ÿ�����֮��Ҫ��������ȼ��������͵�Ԫ�أ����Ѹ���Ԫ�ش�������ɾ����

����
��һ��: num (���Ԫ�ش�����num <= 30)

����10*num�У�ÿ��һ��������n��n < 10000000).

���
ÿ������10��������������������ȼ��������͵�Ԫ�أ������ÿո�����

��������
1
10 7 66 4 5 30 91 100 8 9
�������
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
		if (a % i == 0) {//���i��a������
			int tmp = a / i;//��a/iҲ����������
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
		while (!q1.empty()) {//��q1�е�Ԫ��ת��q2��
			tmp = q1.top();
			q2.push(tmp);
			q1.pop();
		}
		cout << q2.top() << endl;
		q2.pop();
		while (!q2.empty()) {//��ת����
			tmp = q2.top();
			q1.push(tmp);
			q2.pop();
		}
	}
	return 0;
}