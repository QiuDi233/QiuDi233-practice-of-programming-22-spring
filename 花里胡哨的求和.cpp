/*����
���� n ����, ��� n ����, ���е� i �����Ƕ�����ǰ i �����ĺ�

#include<iostream>
#include<vector>
using namespace std;
class A{
// �ڴ˴�������Ĵ���
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
����
.
���
.
��������
3
1 2 3
�������
1
3
6*/

#include<iostream>
#include<vector>
using namespace std;
class A{
// �ڴ˴�������Ĵ���
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
