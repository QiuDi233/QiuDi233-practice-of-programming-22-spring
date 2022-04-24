/*描述
某校园为方便学生订餐，推出食堂预定系统。食宿平台会在前一天提供菜单，学生在开饭时间前可订餐。 食堂每天会推出m个菜，每个菜有固定的菜价和总份数，售卖份数不能超过总份数。 假设共有n个学生点餐，每个学生固定点3个菜，当点的菜售罄时, 学生就买不到这个菜了。 请根据学生预定记录，给出食堂总的预定收入 数据满足1 <= n <= 6000，3 <= m <= 6000，单品菜价不大于1000元，每个菜的配额不超过3000

输入
第一行两个整数n和m，代表有n个学生订餐，共有m个可选的菜
下面m行，每行三个元素，分别是菜名、售价和可提供量，保证菜名不重合，菜价为整数
下面n行，每行三个元素，表示这个学生点的三个菜的菜名
输出
一个整数，表示食堂的收入
样例输入
5 5
yangroupaomo 13 10
jituifan 7 5
luosifen 16 3
xinlamian 12 20
juruo_milktea 999 1
yangroupaomo luosifen juruo_milktea
luosifen xinlamian jituifan
yangroupaomo jituifan juruo_milktea
jituifan xinlamian luosifen
yangroupaomo yangroupaomo yangroupaomo
样例输出
1157*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
struct meal {
	int price;//价格
	int cnt;//份额
	meal(int p,int c):price(p),cnt(c){ }
	meal() {
		price = 0;
		cnt = 0;
	}
};
int main() {
	int n = 0, m = 0;//n个学生 m个菜
	cin >> n >> m;
	map<string, meal>mp;
	string name;
	int price;
	int cnt;
	for (int i = 0; i < m; ++i) {
		cin >> name >> price >> cnt;
		mp.insert(make_pair(name, meal(price, cnt)));
	}
	string food;
	int profit = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> food;
			if (mp[food].cnt>0) {
				profit += mp[food].price;
				mp[food].cnt--;
			}
		}
	}
	cout << profit << endl;
	return 0;
}
