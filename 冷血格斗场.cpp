/*描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，
而只要同一名老会员打一场表演赛，证明自己的实力。

我们假设格斗的实力可以用一个非负整数表示，称为实力值，两人的实力值可以相同。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，
每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有多个人的实力值与他差别相同，则他会选择id最小的那个。

不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。
一开始，facer就算是会员，id为1，实力值1000000000。

输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

样例输入
3
2 3
3 1
4 2
样例输出
2 1
3 2
4 2*/


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
