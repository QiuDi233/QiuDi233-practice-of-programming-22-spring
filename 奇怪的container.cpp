/*����
������գ�����ָ�����

#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
// �ڴ˴�������Ĵ���
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}
����
��һ��������n
�ڶ���������m
���������ַ���s1
���������ַ���s2
���
��һ���� n+2*m
�ڶ����� n + m
�������� s1+s2+s2
�������� s1+s2
��������
5
3
foo
bar
�������
11
8
foobarbar
foobar*/

#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
// �ڴ˴�������Ĵ���
	T t;
public:
	container(T n){
		t=n;
	}
	friend ostream& operator <<(ostream&os,container c){
		os<<c.t;
		return os;
	}
	container operator + (int m){
		return container(t+m);
	}
	container operator + (string s){
		return container(t+s);
	}
	container operator +(container c){
		return container(t+c.t+c.t);
	}
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}
