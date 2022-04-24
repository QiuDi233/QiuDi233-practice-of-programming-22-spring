/*描述
写出函数中缺失的部分，使得函数返回值为一个整数,该整数的后x位和前y位与n相同，其他位和m相同。
请补全calc函数使得程序能达到上述的功能

#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
// 在此处补充你的代码
}
int main() {
  int x, y, t;
  unsigned int n, m;
  cin >> t;
  while (t--) { 
    cin >> n >> m >> x >> y;
    cout << calc(n, m, x, y) << endl;
  }
  return 0;
}
输入
第一行一个整数N，表示多组测试数据。
接下去每行4个整数，分别为n, m ,x, y。 （x+y <= 32）
输出
每组测试数据，输出一个整数，表示题目中的结果。
样例输入
2
258079 4064 5 20
5 2 1 30
样例输出
262143
7*/

#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
// 在此处补充你的代码
	//该整数的后x位和前y位与n相同，其他位和m相同。
	int mask1=(1<<31)>>(y-1);
	if(y==0){
		mask1=0;
	}
	int mask2=~((1<<31)>>(31-x));
	int mask3=mask1|mask2;
	int n_=mask3&n;
	int mask4=~mask3;
	int m_=mask4&m;
	return n_|m_;
}
int main() {
  int x, y, t;
  unsigned int n, m;
  cin >> t;
  while (t--) { 
    cin >> n >> m >> x >> y;
    cout << calc(n, m, x, y) << endl;
  }
  return 0;
}
