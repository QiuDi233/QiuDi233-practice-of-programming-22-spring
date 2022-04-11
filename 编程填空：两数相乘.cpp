/*描述
完善程序，使按指定方式输出

#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
// 在此处补充你的代码
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
输入
第一行是数据组数t
每组数据1行，为两个整数 m 和 n
输出
对每组数据，输出 m * n
样例输入
2
2 5
3 8
样例输出
10
24*/ 

#include <iostream>
using namespace std;
class Number {
public: 
    int num;
    Number(int n): num(n) {}
// 在此处补充你的代码
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
