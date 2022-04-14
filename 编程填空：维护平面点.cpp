/*����
������գ�һ��ʼƽ����һ���㶼û��

ÿ�ο��Բ���һ���㣬ɾ��һ���Ѿ����ڵĵ㣬���߰���x ��y ����ѯһ�����ڵĵ�

��֤�κ�ʱ������������һ����һ�����ϸ�����һ��������·�

������(x1, y1), (x2, y2)���ض���x1 > x2 ��y1 < y2 ������x1 < x2 ��y1 > y2



#include <set>
#include <iostream>
#include <string>
using namespace std;
// �ڴ˴�������Ĵ���
int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		} else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		} else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		} else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}
����
�������ݵ�ÿһ�У���ʽΪ����֮һ��
A x y
R x y
Qx x
Qy y
���� x �� y ���� 0 �� 10^9 ֮�������
A x y ��ʾ����� (x, y)
R x y ��ʾɾ���� (x, y)����֤����
Qx x ��ʾ�ڵ�ǰ���е��У��ҵ���һάΪx�ĵ㣬�����ڶ�ά��ֵ����֤����
Qy y ��ʾ�ڵ�ǰ���е��У��ҵ��ڶ�άΪy�ĵ㣬������һά��ֵ����֤����
�ܹ�������������100000
���
����ÿһ�� Qx �� Qy ���������һ�б�ʾ��Ӧ�Ĵ�
��������
A 3 5
A 4 2
Qx 4
R 4 2
A 4 3
Qy 3
�������
2
4*/ 

#include <set>
#include <iostream>
#include <string>
using namespace std;

// �ڴ˴�������Ĵ��� 
struct myComp {
	bool operator ()(const pair<int, int> &p1,const pair<int, int>& p2)const {
		if (p1.first == -1||p2.first==-1) {//��ѯʱ��-1
			return p1.second > p2.second;
		}
		return p1.first < p2.first;
	}
};
int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		}
		else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		}
		else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		}
		else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}
