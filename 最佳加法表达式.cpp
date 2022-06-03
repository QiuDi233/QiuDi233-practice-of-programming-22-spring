/*����
����n��1��9�����֣�Ҫ��������֮��ڷ�m���Ӻ�(�Ӻ����߱��������֣���ʹ�����õ��ļӷ����ʽ��ֵ��С��
�������ֵ�����磬��1234�аڷ�1���Ӻţ���õİڷ�����12+34,��Ϊ36

����
�в�����15������
ÿ���������С���һ��������m����ʾ��m���Ӻ�Ҫ��( 0<=m<=50)
�ڶ��������ɸ����֡���������n������50,�� m <= n-1
���
��ÿ�����ݣ������С�ӷ����ʽ��ֵ
��������
2
123456
1
123456
4
12345
�������
102
579
15
��ʾ
Ҫ�õ��߾��ȼ��㣬�������������long long ��װ���µĴ�����������ģ������ʽ�İ취���д������ļӷ���*/

#include<iostream>
#include<string>
using namespace std;
int m = 0;//m���Ӻ�Ҫ��
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
	//���s1����s2 ����1 ���ڷ���0 С�ڷ���-1
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
		//������ͬʱ
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
		string dp[60][60];//i���Ӻ� j������
		for (int i = 1; i <= len; ++i) {
			dp[0][i] = str.substr(0, i);
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= len; ++j) {
				if (i >= j)
					continue;
				//���һ���Ӻŷ��ڵ�k������
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