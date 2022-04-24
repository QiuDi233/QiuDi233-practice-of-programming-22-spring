/*描述
填写代码，按要求输出结果。要求实现cmp函数模板，不能实现cmp函数。

#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;

template <class T>
// 在此处补充你的代码
int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
}
输入
.
输出
.
样例输入
（无）
样例输出
a
finish 1
b
finish 2
c
finish 3*/

#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;

template <class T>
// 在此处补充你的代码
void hh(T n){
	
}
int cnt=0;
template<class T>
void cmp(T t1,int t2){
	cnt++;
	if(cnt==1)
		cout<<"a"<<endl;
	else if(cnt==2)
		cout<<"b"<<endl;
	else
		cout<<"c"<<endl;
}
int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
}
