/*����
��д���룬��Ҫ��������

#include <iostream>
using namespace std;

class A {
public:
// �ڴ˴�������Ĵ���
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}
����
��һ������������ t
ÿ������1�У������������� m ,n , k
���
��ÿ�����ݣ����4�У��ֱ��ǣ�
m
2m-n
2m-n
k
��������
1
3 2 10
�������
3
4
4
10*/


#include <iostream>
using namespace std;

class A {
public:
// �ڴ˴�������Ĵ���
	int num;
	A(int m){
		num=m;
	}
	A& getValue(){
		return *this;
	}
	friend ostream& operator <<(ostream&os,A a){
		os<<a.num;
		return os;
	}
	A operator +=(A b){
		num+=b.num;
		return *this;
	}
	A operator -=(int n){
		num-=n;
		return *this;
	}
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}
