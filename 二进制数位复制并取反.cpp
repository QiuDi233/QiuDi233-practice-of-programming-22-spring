/*描述
输入整数a b i j，把b从第i到j位(包括i,j)的二进制位全部取反，并填入a的i到j位中，a的其他位不变。输出a。 最右边一位是第0位。

输入
整数a b i j(范围不超过int)
输出
改变以后的a
样例输入
6123 3344 2 9
样例输出
5871*/

#include<iostream>
using namespace std;
int main(){
	int a=0,b=0,i=0,j=0;
	cin>>a>>b>>i>>j;
	int mask1=(1<<31>>(31-i));
	int mask2=~(1<<31>>(30-j));
	int mask=mask1&mask2;//第i到j位是1 其余位是0
	a=a&(~mask);//把a的第i到j位搞成0
	b=b^mask;//取反
	b=b&mask;//把b的除了i到j位搞成0 
	a=a|b;
	cout<<a<<endl;
	return 0;
}
