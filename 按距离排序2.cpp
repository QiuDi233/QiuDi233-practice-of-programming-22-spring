/*描述
程序填空，输出指定结果

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1,class T2>
struct Closer {
// 在此处补充你的代码
};

int Distance1(int n1,int n2) {
	return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
	return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
	int n;string s;
	while( cin >> n >> s ) {
		sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
		for(int i = 0;i < 10; ++i)
			cout << a[i] << "," ;
		cout << endl;
		sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2)); 
		for(int i = 0;i < 6; ++i)
			cout << b[i] << "," ;
		cout << endl;
	}
	return 0;
}
输入
多组数据，每组一行，是一个整数n和一个字符串s
输出
定义两个整数的距离为两个整数差的绝对值
定义两个字符串的距离为两个字符串长度差的绝对值

对每组数据：
对数组a按和n的距离从小到大排序后输出。距离相同的，值小的排在前面。
然后对数组b，按照和s的距离从小到大输出。距离相同的，字典序小的排在前面
样例输入
2 a123456
4 a12345
样例输出
1,3,0,4,7,8,9,10,15,20,
American,Peking,123456789,Jack,To,abcdefghijklmnop,
4,3,1,7,0,8,9,10,15,20,
Peking,American,Jack,123456789,To,abcdefghijklmnop,*/


#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1,class T2>
struct Closer {
// ÔÚ´Ë´¦²¹³äÄãµÄ´úÂë
	T1 n;
	T2 f;
	Closer(T1 t1,T2 t2){
		n=t1;
		f=t2;
	}
	bool operator()(T1 tt1,T1 tt2){
		if(f(tt1,n)==f(tt2,n))
			return tt1<tt2;
		return f(tt1,n)<f(tt2,n);
	}
};

int Distance1(int n1,int n2) {
	return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
	return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
	int n;string s;
	while( cin >> n >> s ) {
		sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
		for(int i = 0;i < 10; ++i)
			cout << a[i] << "," ;
		cout << endl;
		sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2)); 
		for(int i = 0;i < 6; ++i)
			cout << b[i] << "," ;
		cout << endl;
	}
	return 0;
}
