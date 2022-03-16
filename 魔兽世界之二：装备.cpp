/*描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，
其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)
注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors*/


#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iomanip>
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

#define sword 0
#define bomb 1
#define arrow 2
int case_num;//测试数据组数
int red_energy = 0;//初始生命元
int blue_energy;
int red_num = 0;//编号
int blue_num;

vector<string>red_warrior = { "iceman","lion","wolf","ninja","dragon" };
vector<string>blue_warrior = { "lion","dragon","ninja","iceman","wolf" };

vector<string>weapon = { "sword","bomb","arrow" };

struct warrior {
	int HP;//health point 生命值
	int ATK;//attack攻击力
	double morale;
	int loyalty;
	vector<int>weapon;
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

		int type = make_red % 5;
		if (red_energy >= red_HP[type]) {
			red_energy -= red_HP[type];//可以造雪人
			red_num++;

			warrior temp;
			temp.HP = red_HP[type];
			temp.ATK = 0;
			if (type == red_dragon)
			{
				int w = red_num % 3;//龙获得武器
				temp.weapon.push_back(w);
				temp.morale = red_energy / red_HP[red_dragon];//龙的士气

			}

			if (type == red_iceman)
			{
				int w = red_num % 3;//雪人获得武器
				temp.weapon.push_back(w);
			}


			if (type == red_ninja)
			{
				int w1 = red_num % 3;//忍者获得武器
				int w2 = (red_num + 1) % 3;
				temp.weapon.push_back(w1);
				temp.weapon.push_back(w2);
			}

			if (type == red_lion) {
				int loy = red_energy;
				temp.loyalty = loy;//狮子的忠诚度
			}

			red[type].push_back(temp);

			cout << "red " << red_warrior[type] << " " << red_num << " born with strength " << red_HP[type];
			cout << "," << red[type].size() << " " << red_warrior[type] << " in red headquarter" << endl;

			if (type == red_dragon) {
				cout << "It has a " << weapon[red_num % 3] << ",and it's morale is " << fixed<<setprecision(2)<<(double)red_energy / red_HP[red_dragon] << endl;
			}

			if (type == red_ninja) {
				cout << "It has a " << weapon[red_num % 3] << " and a " << weapon[(red_num + 1) % 3] << endl;
			}

			if (type == red_iceman) {
				cout << "It has a " << weapon[red_num % 3] << endl;
			}

			if (type == red_lion) {
				cout << "It's loyalty is " << red_energy << endl;
			}

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

			if (type == blue_dragon)
			{
				int w = blue_num % 3;//龙获得武器
				temp.weapon.push_back(w);
				temp.morale = blue_energy / blue_HP[blue_dragon];//龙的士气

			}

			if (type == blue_iceman)
			{
				int w =blue_num % 3;//雪人获得武器
				temp.weapon.push_back(w);
			}


			if (type == blue_ninja)
			{
				int w1 = blue_num % 3;//忍者获得武器
				int w2 = (blue_num + 1) % 3;
				temp.weapon.push_back(w1);
				temp.weapon.push_back(w2);
			}

			if (type == blue_lion) {
				int loy = blue_energy;
				temp.loyalty = loy;//狮子的忠诚度
			}


			blue[type].push_back(temp);
			cout << "blue " << blue_warrior[type] << " " << blue_num << " born with strength " << blue_HP[type];
			cout << "," << blue[type].size() << " " << blue_warrior[type] << " in blue headquarter" << endl;

			if (type == blue_dragon) {
				cout << "It has a " << weapon[blue_num % 3] << ",and it's morale is " << fixed<<setprecision(2)<<(double)blue_energy/blue_HP[blue_dragon] << endl;
			}

			if (type == blue_ninja) {
				cout << "It has a " << weapon[blue_num % 3] << " and a " << weapon[(blue_num + 1) % 3] << endl;
			}

			if (type == blue_iceman) {
				cout << "It has a " << weapon[blue_num % 3] << endl;
			}

			if (type == blue_lion) {
				cout << "It's loyalty is " << blue_energy << endl;
			}


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
