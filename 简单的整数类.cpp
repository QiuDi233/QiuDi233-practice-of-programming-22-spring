/*����
���������� m,n( 0<=m,n <= 9)��������ǵĳ˻�

#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}
// �ڴ˴�������Ĵ���
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
����
��������m,n��ȷ���˻�С��10
���
���ǵĳ˻�
��������
3 2
�������
6*/

#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}
// �ڴ˴�������Ĵ���
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
