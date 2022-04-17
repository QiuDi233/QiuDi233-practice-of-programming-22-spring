/*描述
宠物小精灵的世界中，每位训练师都在收集自己的小精灵。但是，训练师的背包里只能同时携带6只小精灵。如果一位训练师抓到了更多的精灵，那么最早抓到的精灵将被自动传送到电脑中，保证持有的小精灵数量依然是6只。 训练师也可以随时从电脑中取出精灵，取出的精灵将从电脑中传送到训练师的背包里。取出的精灵同样被认为是最新的，导致背包中最早取出或抓到的精灵被替换到电脑中，训练师持有的精灵数量依然是6只。 初始状态下，所有训练师的背包中都没有小精灵，电脑中也没有任何训练师的精灵。

输入
输入数据包含多组测试。第一行一个整数T(1<=T<=20)，表示测试数据数目。
每组数据第一行有一个正整数N(1<=N<=20000)表示发生事件的数目。
接下来有N行分别表示发生的事件。
一共有两种事件：
C X, Y 表示训练师X抓到了精灵Y
T X, Y 表示训练师X试图从电脑中取出精灵Y。

X和Y都是长度在20以下的由字母或数字构成的字符串。

小精灵的世界中同样存在着作恶多端的火箭队。他们试图利用电脑的漏洞，从电脑中取出本不属于自己的小精灵。因此，电脑需要识别并拒绝取出这种请求。注意，如果一只小精灵仅存在于训练师的背包中而未被传送至电脑，该训练师也不能取出这只精灵。相同训练师不会多次抓到相同名字的精灵。
输出
对于每次从电脑中取出小精灵的请求，输出一行。成功则输出Success，失败则输出Failed。
样例输入
1 10
C satoshi pikachu1
C satoshi pikachu2
C satoshi pikachu3
C satoshi pikachu4
C satoshi pikachu5
C satoshi pikachu6
C satoshi pikachu7
T satoshi pikachu2
T satoshi pikachu1
T pikachu pikachu2
样例输出
Failed
Success
Failed*/

#include<iostream>
#include<string>
#include<map> 
#include<queue>
#include<list>
using namespace std;
class pokemon {
public:
	string name;
	int n;

	pokemon(int n_, string name_) :n(n_), name(name_) { }
};
struct cmp {
	bool operator()(pokemon p1, pokemon p2) {
		return p1.n > p2.n;
	}
};
int main() {
	int T = 0;
	int N = 0;
	string X, Y;
	char ch;
	cin >> T;
	while (T--) {
		cin >> N;
		int cnt = 0;
		map<string, priority_queue<pokemon, vector<pokemon>, cmp>>backpack;
		map<string, list<pokemon>>store;
		while (N--) {
			cnt++;
			cin >> ch >> X >> Y;

			if (ch == 'C') {
				//训练师X抓到了精灵Y

				if (backpack.find(X) != backpack.end()) {//训练师已经有小精灵了
					if (backpack[X].size() == 6) {//放满了
						pokemon tmp = backpack[X].top();//要被替换出去的小精灵
						backpack[X].pop();
						backpack[X].push(pokemon(cnt, Y));
						store[X].push_back(tmp);//把被替换的放到仓库里
					}
					else {//还没放满
						backpack[X].push(pokemon(cnt, Y));
					}
				}
				else {
					priority_queue<pokemon, vector<pokemon>, cmp>q;
					q.push(pokemon(1, Y));
					backpack.insert(make_pair(X, q));//为训练师建一个背包
					list<pokemon>l;//为训练师建立一个仓库
					store.insert(make_pair(X, l));
				}
			}
			if (ch == 'T') {
				//训练师X试图从电脑中取出精灵Y
				bool f = false;
				list<pokemon>::iterator it = store[X].begin();
				for (; it != store[X].end(); ++it) {
					if (it->name == Y) {
						//放到包包里
						it->n = cnt;//更新数值 使之成为最新
						if (backpack[X].size() == 6) {//放满了
							pokemon tmp = backpack[X].top();//要被替换出去的小精灵
							backpack[X].pop();
							backpack[X].push(*it);
							store[X].push_back(tmp);//把被替换的放到仓库里
						}
						else {//还没放满
							backpack[X].push(*it);
						}
						//放好了

						store[X].erase(it);
						f = true;
						cout << "Success" << endl;
						break;
					}
				}
				if (!f) {
					cout << "Failed" << endl;
				}
			}
		}
	}
	return 0;
}
