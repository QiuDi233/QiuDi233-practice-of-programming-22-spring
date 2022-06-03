/*描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，
并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1
输出
对每组数据，输出最小加法表达式的值
样例输入
2
123456
1
123456
4
12345
样例输出
102
579
15
提示
要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。*/

#include<iostream>
#include<string>
using namespace std;
int m = 0;//m个加号要放
string reverse(string s) {
	string str;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		str+= s[len - 1 - i];
	}
	return str;
}
string add(string s1, string s2) {
	string str1 = reverse(s1);
	string str2 = reverse(s2);
	int carry = 0;
	int p = 0;
	int len1 = s1.length();
	int len2 = s2.length();
	string ans;
	int tmp = 0;
	while (p < len1 && p < len2) {
		tmp = (str1[p] - '0' + str2[p] - '0')+carry;
		ans+= tmp % 10 + '0';
		carry = tmp / 10;
		p++;
	}
	while (p < len1) {
		tmp = str1[p] - '0' + carry;
		ans+= tmp % 10 + '0';
		carry = tmp / 10;
		p++;
	}
	while (p < len2) {
		tmp = str2[p] - '0' + carry;
		ans+= tmp % 10 + '0';
		carry = tmp / 10;
		p++;
	}
	tmp =  carry;
	ans += tmp % 10 + '0';
	carry = tmp / 10;
	p++;
	ans = reverse(ans);
	int q = 0;
	while (ans[q] == '0') {
		q++;
	}
	return ans.substr(q,ans.length()-q);
}
int cmp(string s1, string s2) {
	//如果s1大于s2 返回1 等于返回0 小于返回-1
	if (s1 == s2) {
		return 0;
	}
	if (s1.length() > s2.length()) {
		return 1;
	}
	if (s1.length() < s2.length()) {
		return -1;
	}
	for (int i = 0; i < s1.length(); ++i) {
		//长度相同时
		if (s1[i] > s2[i]) {
			return 1;
		}
		if (s1[i] < s2[i]) {
			return -1;
		}
	}
}
string Min(string s1, string s2) {
	if (cmp(s1, s2) == 1) {
		return s2;
	}
	return s1;
} 
int main() {
	string str;
	while (cin >> m) {
		cin >> str;
		int len = str.length();
		string dp[60][60];//i个加号 j个数字
		for (int i = 1; i <= len; ++i) {
			dp[0][i] = str.substr(0, i);
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= len; ++j) {
				if (i >= j)
					continue;
				//最后一个加号放在第k个数后
				for (int k = i; k < j; ++k) {
					if (k == i) {
						dp[i][j] = add(dp[i - 1][k], str.substr(k, j - k));
						continue;
					}
					dp[i][j] = Min(dp[i][j], add(dp[i - 1][k], str.substr(k, j - k)));
				}

			}
		}
		cout << dp[m][len] << endl;
	}
	return 0;
}