/*描述
输入两个数 m,n( 0<=m,n <= 9)，输出它们的乘积

#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}
// 在此处补充你的代码
};

int main() { 
    char m,n;
    cin >> m >>  n;
    MyNum n1(m), n2(n);
    MyNum n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
输入
两个数，m,n，确保乘积小于10
输出
它们的乘积
样例输入
3 2
样例输出
6*/

#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}
// 在此处补充你的代码
	friend MyNum operator *(MyNum n1,MyNum n2){
		return MyNum((n1.C-'0')*(n2.C-'0')+'0');
	}
	operator int(){
		return C-'0';
	}
};

int main() { 
    char m,n;
    cin >> m >>  n;
    MyNum n1(m), n2(n);
    MyNum n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
