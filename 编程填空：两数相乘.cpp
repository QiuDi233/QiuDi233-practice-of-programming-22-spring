/*����
���Ƴ���ʹ��ָ����ʽ���

#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
// �ڴ˴�������Ĵ���
};
int main() {
	int t;
	int m,n;
	cin >> t;
	while(t--) {
	    cin >> m>> n;
	    Number n1(m), n2 = n1 * n;
	    if( m * n == n2 )
	    	cout << n2 << endl;
	}
    return 0;
}
����
��һ������������t
ÿ������1�У�Ϊ�������� m �� n
���
��ÿ�����ݣ���� m * n
��������
2
2 5
3 8
�������
10
24*/ 

#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
// �ڴ˴�������Ĵ���
	friend ostream& operator<<(ostream&os,Number n){
		os<<n.num;
		return os;
	}
	friend Number operator*(Number n1,int n2){
		return Number(n1.num*n2);
	}
	friend bool operator ==(Number n1,Number n2){
		return n1.num==n2.num;
	}
};
int main() {
	int t;
	int m,n;
	cin >> t;
	while(t--) {
	    cin >> m>> n;
	    Number n1(m), n2 = n1 * n;
	    if( m * n == n2 )
	    	cout << n2 << endl;
	}
    return 0;
}
