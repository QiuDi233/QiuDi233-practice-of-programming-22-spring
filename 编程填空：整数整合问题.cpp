/*����
д��������ȱʧ�Ĳ��֣�ʹ�ú�������ֵΪһ������,�������ĺ�xλ��ǰyλ��n��ͬ������λ��m��ͬ��
�벹ȫcalc����ʹ�ó����ܴﵽ�����Ĺ���

#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
// �ڴ˴�������Ĵ���
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
����
��һ��һ������N����ʾ����������ݡ�
����ȥÿ��4���������ֱ�Ϊn, m ,x, y�� ��x+y <= 32��
���
ÿ��������ݣ����һ����������ʾ��Ŀ�еĽ����
��������
2
258079 4064 5 20
5 2 1 30
�������
262143
7*/

#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
// �ڴ˴�������Ĵ���
	//�������ĺ�xλ��ǰyλ��n��ͬ������λ��m��ͬ��
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
