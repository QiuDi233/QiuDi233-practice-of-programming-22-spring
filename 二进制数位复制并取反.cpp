/*����
��������a b i j����b�ӵ�i��jλ(����i,j)�Ķ�����λȫ��ȡ����������a��i��jλ�У�a������λ���䡣���a�� ���ұ�һλ�ǵ�0λ��

����
����a b i j(��Χ������int)
���
�ı��Ժ��a
��������
6123 3344 2 9
�������
5871*/

#include<iostream>
using namespace std;
int main(){
	int a=0,b=0,i=0,j=0;
	cin>>a>>b>>i>>j;
	int mask1=(1<<31>>(31-i));
	int mask2=~(1<<31>>(30-j));
	int mask=mask1&mask2;//��i��jλ��1 ����λ��0
	a=a&(~mask);//��a�ĵ�i��jλ���0
	b=b^mask;//ȡ��
	b=b&mask;//��b�ĳ���i��jλ���0 
	a=a|b;
	cout<<a<<endl;
	return 0;
}
