#include<iostream>
#include<map>
#include<fstream>
using namespace std;
int main() {
	//ʵ��ֵ������ͬ �Ǽ���֮�������ʵ��ֵ��ͬ�ľͰ�id��Ĳ��ӽ�ȥ
	ofstream fout("1.txt");
	map<int, int>club;//ʵ�� id
	int n = 0;
	cin >> n;
	int id = 0, force = 0;
	club.insert(pair<int, int>(1000000000, 1));
	while (n--) {
		cin >> id >> force;
		if (club.count(force)==1) {//����Ѿ��������ʵ����
			map<int, int>::iterator it;
			it = club.find(force);
			cout << id << " " << it->second << endl;
			//Ȼ��id��Ĳ��ӽ�ȥ
		}
		else {
			//�����û�����ʵ����
			club.insert(pair<int, int>(force, id));
			map<int, int>::iterator it, pre, last;
			it = club.find(force);
			pre = last = it;
			pre--;
			last++;
			if (it == club.begin()) {//����
				cout << id << " " << last->second << endl;
			}
			else if (last == club.end()) {//��ǿ
				cout << id << " " << pre->second << endl;
			}
			else {
				if (it->first - pre->first > last->first - it->first) {
					cout << id << " " << last->second << endl;
				}
				if (it->first - pre->first < last->first - it->first) {
					cout << id << " " << pre->second << endl;
				}
				if (it->first - pre->first == last->first - it->first) {
					if (pre->second < last->second) {
						cout << id << " " << pre->second << endl;//��idС��
					}
					else {
						cout << id << " " << last->second << endl;
					}
				}
			}
		}
	}
	return 0;
}