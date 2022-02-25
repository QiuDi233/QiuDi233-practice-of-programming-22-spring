/*描述
下面程序的输出是：

3+4i

5+6i

请补足Complex类的成员函数。不能加成员变量。

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
输入
无
输出
3+4i
5+6i
样例输入
None
样例输出
3+4i
5+6i*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
Complex& operator=(string s){
	int rr=0;
	int ii=0;
	char ch;
	//sccanf(s,"%d %c %d %c",rr,ch,ii,ch); 没sscanf的头文件用不了
	int j;
	for(j=0;j<s.size()&&s[j]!='+';++j){
		rr*=10;
		rr+=s[j]-'0';
	}
	j++;
	for(;j<s.size()&&s[j]!='i';++j){
		ii*=10;
		ii+=s[j]-'0'; 
	}
	r=rr;
	i=ii;
	return *this;
}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
