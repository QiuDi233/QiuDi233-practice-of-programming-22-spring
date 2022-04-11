/*����
����һ��������ͳ�������ж����������������������Ʊ�ʾ�ĵ�nλΪ1��

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// �ڴ˴�������Ĵ���
int main(int argc, char** argv) {	
	int n, x;
	vector<int> intVec;
	cin>>n>>x; 
	while(x) {
		intVec.push_back(x);
		cin>>x;
	}
	cout<<count_if(intVec.begin(), intVec.end(), Pred(n))<<endl;
	return 0;
}
����
�������ݰ�������
��һ��Ϊ������n (0 <= n < 32)
�ڶ�����һ���ͳ�Ƶ���������0��ʾ������
���
���һ�У�Ϊ���������������Ʊ�ʾ�ĵ�nλΪ1������������
��������
0
1 2 3 4 5 0
�������
3
��ʾ
���ұ�һλΪ��0λ*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// �ڴ˴�������Ĵ���
struct Pred{
	int n;
	Pred(int n_){
		n=n_;
	}
	bool operator()(int x){
		int mask=(1<<n);
		return (mask&x)>>n;
	}
};
int main(int argc, char** argv) {	
	int n, x;
	vector<int> intVec;
	cin>>n>>x; 
	while(x) {
		intVec.push_back(x);
		cin>>x;
	}
	cout<<count_if(intVec.begin(), intVec.end(), Pred(n))<<endl;
	return 0;
}
