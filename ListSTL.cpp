/*����
дһ����������������
new id �����½�һ��ָ�����Ϊid������(id < 10000)
add id num��������Ϊid�����м�������
num merge id1 id2�������id1����id2,�����κ��£�����鲢����id1��id2�е���������id2���
unique id����ȥ������id���ظ���Ԫ��
out id ������С����������Ϊid�������е�Ԫ�أ��Կո����

����
��һ��һ����n����ʾ�ж��ٸ�����( n����������������)���Ժ�n��ÿ��һ�����
���
����ĿҪ�������
��������
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1
�������
1 2 3 
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4*/


#include<iostream>
#include<list>
#include<string>
using namespace std;
int main() {
	list<int>L[10005];
	int n = 0;
	string op;
	int id = 0, num = 0;
	int id1 = 0, id2 = 0;
	cin >> n;
	while (n--) {
		cin >> op;
		if (op == "new") {
			cin >> id;
		}
		if (op == "add") {
			cin >> id >> num;
			L[id].push_back(num);
		}
		if (op == "merge") {
			cin >> id1 >> id2;
			if (id1 == id2)
				continue;
			L[id1].merge(L[id2]);
			
		}
		if (op == "unique") {
			cin >> id;
			L[id].sort();
			L[id].unique();
		}
		if (op == "out") {
			cin >> id;
			L[id].sort();
			list<int>::iterator it;
			for (it = L[id].begin(); it != L[id].end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
		}
	}
	return 0;
}