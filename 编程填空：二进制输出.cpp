/*����
����һ��int��ʾ��Χ�ڵ�������x�����������Ʊ�ʾ��һ��Ҫ���31λ�����㴦Ҫ��0��

#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// �ڴ˴�������Ĵ���
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
����
��һ��������n(n<15)����ʾ��n��������Ҫ����
�ڶ�����n��������
���
��ÿ�������������������������Ʊ�ʾ������31λ����0���뵽31λ
��������
3
1 2 3
�������
0000000000000000000000000000001
0000000000000000000000000000010
0000000000000000000000000000011*/

#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x){
// �ڴ˴�������Ĵ���
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
