/*����
��д���룬��Ҫ��������

#include <cstdio>
#include <iostream>
using namespace std;

class f {
// �ڴ˴�������Ĵ���
};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}
����
.
���
.
��������
(��)
�������
2
6
400
63
6
10*/

#include <cstdio>
#include <iostream>
using namespace std;

class f {
// �ڴ˴�������Ĵ���
	int n;
public:
	f(int n_){
		n=n_;
	}
	f(int n_,int m_){
		n=n_*m_;
	}
	friend ostream& operator<<(ostream&os,f num){
		os<<num.n;
		return os;
	}
	int operator()(int m_){
		return m_-n;
	} 
};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}
