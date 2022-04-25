/*描述
给出一个int表示范围内的正整数x，输出其二进制表示。一共要输出31位，不足处要补0。

#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// 在此处补充你的代码
}
int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}
输入
第一行是整数n(n<15)，表示有n个正整数要处理
第二行是n个正整数
输出
对每个给出的正整数，输出其二进制表示。不足31位则用0补齐到31位
样例输入
3
1 2 3
样例输出
0000000000000000000000000000001
0000000000000000000000000000010
0000000000000000000000000000011*/

#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// 在此处补充你的代码
	string s;
	int cnt = 0;
	while (x) {
		cnt++;
		s += x % 2 + '0';
		x /= 2;
	}
	while (cnt <= 31) {
		s += '0';
		cnt++;
	}
	string ss;
	for (int i = 0; i < 31; ++i) {
		ss+= s[30-i];
	}
	return ss;
}
int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}
