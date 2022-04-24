/*描述
读入 n 个数, 输出 n 个数, 其中第 i 个数是读入中前 i 个数的和

#include<iostream>
#include<vector>
using namespace std;
class A{
// 在此处补充你的代码
};
int A::presum=0;
int main(){
  int n;cin>>n;
  vector<A*> p;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    p.push_back(new A(x));
  }
  for(int i=0;i<n;i++){
    p[i]->output();
  }
  return 0;
}
输入
.
输出
.
样例输入
3
1 2 3
样例输出
1
3
6*/

#include<iostream>
#include<vector>
using namespace std;
class A{
// 在此处补充你的代码
	static int presum;
	int sum;
public:
	void output()
	{
		cout<<sum<<endl;
	}	
	A(int n_){
		presum+=n_;
		sum=presum;
	}
};
int A::presum=0;
int main(){
  int n;cin>>n;
  vector<A*> p;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    p.push_back(new A(x));
  }
  for(int i=0;i<n;i++){
    p[i]->output();
  }
  return 0;
}
