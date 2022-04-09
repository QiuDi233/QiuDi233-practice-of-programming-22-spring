#include<iostream>
#include<map>
#include<fstream>
using namespace std;
int main() {
	//实力值可以相同 那加入之后如果有实力值相同的就把id大的不加进去
	ofstream fout("1.txt");
	map<int, int>club;//实力 id
	int n = 0;
	cin >> n;
	int id = 0, force = 0;
	club.insert(pair<int, int>(1000000000, 1));
	while (n--) {
		cin >> id >> force;
		if (club.count(force)==1) {//如果已经有了这个实力的
			map<int, int>::iterator it;
			it = club.find(force);
			cout << id << " " << it->second << endl;
			//然后id大的不加进去
		}
		else {
			//如果还没有这个实力的
			club.insert(pair<int, int>(force, id));
			map<int, int>::iterator it, pre, last;
			it = club.find(force);
			pre = last = it;
			pre--;
			last++;
			if (it == club.begin()) {//最弱
				cout << id << " " << last->second << endl;
			}
			else if (last == club.end()) {//最强
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
						cout << id << " " << pre->second << endl;//打id小的
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
