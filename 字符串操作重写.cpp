/*����
����n���ַ�������1��ʼ��ţ���ÿ���ַ����е��ַ�λ�ô�0��ʼ��ţ�����Ϊ1-500�������������ɲ�����

copy N X L��ȡ����N���ַ�����X���ַ���ʼ�ĳ���ΪL���ַ�����
add S1 S2���ж�S1��S2�Ƿ�Ϊ0-99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ�����
find S N���ڵ�N���ַ����д���ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
rfind S N���ڵ�N���ַ����д��ҿ�ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
insert S N X���ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ�����
reset S N������N���ַ�����ΪS��
print N����ӡ�����N���ַ�����
printall����ӡ��������ַ�����
over������������
����N��X��L����find��rfind�������ʽ���ɣ�S��S1��S2����copy��add�������ʽ���ɡ�

����
��һ��Ϊһ������n��n��1-20֮�䣩


������n��Ϊn���ַ������ַ����������ո񼰲�������ȡ�


������������Ϊһϵ�в�����ֱ��over������

���
���ݲ�����ʾ�����Ӧ�ַ�����

��������
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
�������
Op29adfk48
358
329strjvc
Op29adfk48
35a8
��ʾ
�Ƽ�ʹ��string���е���ز���������*/

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
			//��������
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