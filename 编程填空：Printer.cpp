/*����
������³���ʹ�����������x���Լ���������������
����x�������������Ȼ�����������ַ��������ַ������ȴ���x���ַ������

#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;


class Printer{
// �ڴ˴�������Ĵ���
int main(){

	int t;
	cin >> t;
	while(t--) {
		int n,x;
		cin>>x>>n;
		
		vector<int> intVec;
		for(int i = 0;i < n; ++i) {
			int y;
			cin >> y;
			intVec.push_back(y);
		}
		for_each(intVec.begin(), intVec.end(), Printer(x));
		cout<<endl;
		
		vector<string> strVec;
		for(int i = 0;i < n; ++i) {
			string str;
			cin >> str;
			strVec.push_back(str);
		}
		for_each(strVec.begin(), strVec.end(), Printer(x));
		cout<<endl;
	}
	return 0;
}
����
��һ��������t����ʾһ��t������
ÿ������������
��һ��������x������ n
�ڶ�����n������
��������n�������ո���ַ���
���
��ÿ������
�Ȱ�ԭ�������һ���д���x��������(���ݱ�֤���������
�ٰ�ԭ������ڶ����г��ȴ���x���ַ��� (���ݱ�֤���������
��������
2
5 6
1 3 59 30 2 40
this is hello please me ha
1 1
4
this
�������
59,30,40,
please,
4,
this,*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;


class Printer{
// �ڴ˴�������Ĵ���
	int x;
public:
	Printer(int x_):x(x_){	}
	
	void operator()(int num){
		if(num>x){
			cout<<num<<",";
		}
	} 
	void operator()(string s){
		if(s.length()>x){
			cout<<s<<",";
		}
	}
}; 
int main(){

	int t;
	cin >> t;
	while(t--) {
		int n,x;
		cin>>x>>n;
		
		vector<int> intVec;
		for(int i = 0;i < n; ++i) {
			int y;
			cin >> y;
			intVec.push_back(y);
		}
		for_each(intVec.begin(), intVec.end(), Printer(x));
		cout<<endl;
		
		vector<string> strVec;
		for(int i = 0;i < n; ++i) {
			string str;
			cin >> str;
			strVec.push_back(str);
		}
		for_each(strVec.begin(), strVec.end(), Printer(x));
		cout<<endl;
	}
	return 0;
}
