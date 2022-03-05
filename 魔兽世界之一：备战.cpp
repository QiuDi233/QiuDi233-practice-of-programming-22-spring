/*描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors*/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
#define red_iceman 0
#define red_lion 1
#define red_wolf 2
#define red_ninja 3
#define red_dragon 4

#define blue_lion 0
#define blue_dragon 1
#define blue_ninja 2
#define blue_iceman 3
#define blue_wolf 4

int case_num;//测试数据组数
int red_energy = 0;//初始生命元
int blue_energy;
int red_num = 0;//编号
int blue_num;

vector<string>red_warrior = { "iceman","lion","wolf","ninja","dragon" };
vector<string>blue_warrior = { "lion","dragon","ninja","iceman","wolf" };

struct warrior {
	int HP;//health point 生命值
	int ATK;//attack攻击力
};

//初始血量值


vector<int>red_HP = { 0,0,0,0,0 };
vector<int>blue_HP = { 0,0,0,0,0 };

vector<vector<warrior>>red;//第一维为各种武士 第二维为每种武士的每一个
vector<vector<warrior>>blue;//第一维为各种武士 第二维为每种武士的每一个

void input() {
	int life_energy;
	cin >> life_energy;
	red_energy = life_energy;
	blue_energy = life_energy;

	int dragon_HP;
	int ninja_HP;
	int iceman_HP;
	int lion_HP;
	int wolf_HP;

	cin >> dragon_HP;
	cin >> ninja_HP;
	cin >> iceman_HP;
	cin >> lion_HP;
	cin >> wolf_HP;

	red_HP[red_iceman] = iceman_HP;
	red_HP[red_lion] = lion_HP;
	red_HP[red_wolf] = wolf_HP;
	red_HP[red_ninja] = ninja_HP;
	red_HP[red_dragon] = dragon_HP;

	blue_HP[blue_iceman] = iceman_HP;
    blue_HP[blue_lion] = lion_HP;
	blue_HP[blue_wolf] = wolf_HP;
	blue_HP[blue_ninja] = ninja_HP;
	blue_HP[blue_dragon] = dragon_HP;

}
void warrior_born(const int& time, int& make_blue, int& make_red, bool& red_enough, bool& blue_enough, int& red_energy, int& blue_energy) {
	bool f[5];//不够造人
	if (red_enough) {
		printf("%03d", time);
		cout << " ";
		for (int i = 0; i < 5; i++)
			f[i] = true;
	}
	

	while (red_enough) {
	
		int type =make_red%5;
			if (red_energy >= red_HP[type]) {
				red_energy -= red_HP[type];//可以造雪人
				red_num++;
				warrior temp;
				temp.HP = red_HP[type];
				temp.ATK = 0;

				red[type].push_back(temp);
				cout <<"red "<< red_warrior[type]<<" "<< red_num << " born with strength " << red_HP[type];
				cout << "," << red[type].size()<<" " << red_warrior[type]<<" in red headquarter" << endl;
				break;
			}
			else {
				f[type] = false;//不够造人
				if (!f[red_iceman] && !f[red_wolf] && !f[red_lion] && !f[red_dragon] && !f[red_ninja]) {
					//如果全都不够

					cout << "red headquarter stops making warriors" << endl;
					red_enough = false;
				}
				else {
					make_red++;
				}
			}
	}


	if (blue_enough) {
		printf("%03d", time);
		cout << " ";
		for (int i = 0; i < 5; i++)
			f[i] = true;
	}


	while (blue_enough) {
		int type = make_blue % 5;
		if (blue_energy >= blue_HP[type]) {
			blue_energy -= blue_HP[type];//可以造雪人
			blue_num++;
			warrior temp;
			temp.HP = blue_HP[type];
			temp.ATK = 0;

			blue[type].push_back(temp);
			cout <<"blue "<< blue_warrior[type] <<" "<< blue_num << " born with strength " << blue_HP[type];
			cout << "," << blue[type].size() <<" "<< blue_warrior[type] << " in blue headquarter" << endl;
			break;

		}
		else {
			f[type] = false;//不够造人
			if (!f[blue_lion] && !f[blue_ninja] && !f[blue_wolf] && !f[blue_dragon] && !f[blue_iceman]) {
				//如果全都不够

				cout << "blue headquarter stops making warriors" << endl;
				blue_enough = false;
			}
			else {
				make_blue++;
			}
		}
	}
	
}
int main() {
	cin >> case_num;

	for (int i = 1; i <= case_num; i++) {
		red.clear();
		blue.clear();

		vector<warrior>temps;
		for (int j = 0; j < 5; j++) {
			red.push_back(temps);
			blue.push_back(temps);
		}

		input();
		cout << "Case:" << i << endl;
		int time = 0;//时间
		bool red_enough = true;
		bool blue_enough = true;


		int make_blue = time;
		int make_red = time;

		red_num = 0;
		blue_num = 0;

	
		while (red_enough || blue_enough) {

			warrior_born(time, make_blue, make_red, red_enough, blue_enough, red_energy, blue_energy);
			time++;
			make_red++;
			make_blue++;
		}
	}
	return 0;
}
