/*描述
给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：

copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
reset S N：将第N个字符串变为S。
print N：打印输出第N个字符串。
printall：打印输出所有字符串。
over：结束操作。
其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

输入
第一行为一个整数n（n在1-20之间）


接下来n行为n个字符串，字符串不包含空格及操作命令等。


接下来若干行为一系列操作，直到over结束。

输出
根据操作提示输出对应字符串。

样例输入
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over
样例输出
Op29adfk48
358
329strjvc
Op29adfk48
35a8
提示
推荐使用string类中的相关操作函数。*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>v;
string get_s();
int get_nxl();
int find() {
	string s=get_s();
	int n = get_nxl();
	return v[n].find(s);
}
int rfind() {
	string s = get_s();
	int n = get_nxl();
	return v[n].rfind(s);
}
string copy() {
	int n = get_nxl();
	int x = get_nxl();
	int l = get_nxl();
	return v[n].substr(x, l);
}
string add() {
	string s1 = get_s();
	string s2 = get_s();
	bool is_num = true;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] < '0' || s1[i]>'9') {
			//不是数字
			is_num = false;
		}
	}
	for (int i = 0; i < s2.size(); ++i) {
		if (s2[i] < '0' || s2[i]>'9') {
			is_num = false;
		}
	}
	if (!is_num||atoi(s1.c_str())>99999|| atoi(s2.c_str()) > 99999) {
		return s1 + s2;
	}
	else {
		int num1 = atoi(s1.c_str());
		int num2 = atoi(s2.c_str());
		return to_string(num1 + num2);
	}
}
void reset() {
	string s = get_s();
	int n = get_nxl();
	v[n] = s;
}
int get_nxl() {
	string s;
	cin >> s;
	if (s == "find") {
		return find();
	}
	if (s == "rfind") {
		return rfind();
	}
	return atoi(s.c_str());
}
string get_s() {
	string str;
	cin >> str;
	if (str == "copy") {
		return copy();
	}
	if (str == "add") {
		return add();
	}
	return str;
}
void insert() {
	string s = get_s();
	int n = get_nxl();
	int x = get_nxl();
	v[n].insert(x, s);
}
int main() {
	int T = 0;
	cin >> T;

	string str;
	v.push_back("hhh");
	int n = 0;
	int x = 0;
	int l = 0;
	string s;
	string s1, s2;
	for (int i = 0; i < T; ++i) {
		cin >> str;
		v.push_back(str);
	}
	string op;
	while (true) {
		cin >> op;
		if (op == "over") {
			break;
		}
		if (op == "copy") {
			copy();
		}
		if (op == "add") {
			add();
		}
		if (op == "find") {
			cout<<find()<<endl;
		}
		if (op == "rfind") {
			cout<<rfind()<<endl;
		}
		if (op == "insert") {
			insert();
		}
		if (op == "reset") {
			reset();
		}
		if (op == "print") {
			cin >> n;
			cout << v[n] << endl;
		}
		if (op == "printall") {
			for (int i = 1; i < v.size(); ++i) {
				cout << v[i] << endl;
			}
		}

	}
	return 0;
}