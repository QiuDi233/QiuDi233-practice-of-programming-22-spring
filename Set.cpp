/*����
����һ���������������ظ�Ԫ�أ�����ʼΪ�ա����Ƕ������²�����
add x ��x���뼯��
del x �Ѽ�����������x��ȵ�Ԫ��ɾ��
ask x �Լ�����Ԫ��x�����ѯ��
��ÿ�ֲ���������Ҫ��������������
add ��������󼯺���x�ĸ���
del �������ǰ������x�ĸ���
ask �����0��1��ʾx�Ƿ��������뼯�ϣ�0��ʾ�������룩���������ǰ������x�ĸ������м��ÿո�񿪡�
����
��һ����һ������n����ʾ��������0<=n<=100000��
����n�������Description��������
���
��n�У�ÿ�а�Ҫ�������
��������
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
�������
1
2
1 2
0 0
0
2
1 0
��ʾ
Please use STL��s set and multiset to finish the task*/

#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	multiset<int>s;
	set<int>s1;
	int n;
	cin >> n;
	string op;
	int x = 0;
	while (n--) {
		cin >> op;
		cin >> x;
		if (op == "add")
		{
			s.insert(x);
			s1.insert(x);
			cout << s.count(x) << endl;
		}
		if (op == "del") {
			
			cout << s.count(x) << endl;
			s.erase(x);
		}
		if (op == "ask") {
			if (s1.count(x)) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			cout << " " << s.count(x) << endl;
		}
	}
	return 0;
}