/*����
Fibonacci����ָ�������е�һ��͵ڶ���Ϊ1��֮��ÿһ����֮ǰ����ĺ������ɵ����С� ���ж������ݣ�ÿ�����ݸ���һ������n���������Fibonacci���е�ǰn-1�

#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// �ڴ˴�������Ĵ���
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}
����
ÿ������һ�У�����n
������0��β
���
��ÿ���������ǰ n-1��
��������
3
0
�������
1 1*/

#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// �ڴ˴�������Ĵ���
class Fib {
	int n;//����
	int* p;
	int i;//��������ڼ��� 
public:
	Fib(int n_) {
		n = n_;
		i = n;
		p = new int[100];
		p[0] = 1; p[1] = 1;
		for (int i = 2; i < 100; ++i) {
			p[i] = p[i - 1] + p[i - 2];
		}
	}
	Fib operator++() {
		i++;
		return *this;
	}
	int operator*() {
		return p[i-1];
	}
	bool operator!=(Fib f) {
		return !(i == f.i);
	}
};
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}
