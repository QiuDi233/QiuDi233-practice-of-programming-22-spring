/*描述
Fibonacci数列指的是数列第一项和第二项为1，之后每一项是之前两项的和所构成的数列。 现有多组数据，每组数据给出一个数字n，请你输出Fibonacci数列的前n-1项。

#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// 在此处补充你的代码
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
输入
每组数据一行，整数n
输入以0结尾
输出
对每组数据输出前 n-1项
样例输入
3
0
样例输出
1 1*/

#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// 在此处补充你的代码
class Fib {
	int n;//项数
	int* p;
	int i;//正在输出第几项 
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
