/*����
д��������ȱʧ�Ĳ��֣�ʹ�ú�������ֵΪһ������,�������ĵ�iλ��m�ĵ�iλ��ͬ������λ��n��ͬ��

��ʹ�á�һ�д��롿��ȫbitManipulation1����ʹ�ó����ܴﵽ�����Ĺ���

#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// �ڴ˴�������Ĵ���
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
����
��һ�������� t����ʾ����������
ÿ��������ݰ���һ�У����������� n, m �� i (0<=i<=31)
���
��ÿ���������ݣ�ÿ��������ͱ���n�仯��Ľ��
��������
1
1 2 1
�������
3
��ʾ
�����Ƶ����ұ��ǵ�0λ*/ 
#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
	return n&(~(1<<i))|m&(1<<i);
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
