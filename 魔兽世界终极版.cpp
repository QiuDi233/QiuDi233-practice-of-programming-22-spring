#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<algorithm>
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

#define blue_headquarter city_num+1
#define red_headquarter 0

#define loss_HP 9
#define add_ATK 20

#define red_color 0
#define blue_color 1

#define alive 0
#define dying 1
#define dead 2

#define draw 2

#define no_flag 2
#define red_flag 0
#define blue_flag 1

#define none 0

#define red_first 0
#define blue_first 1

#define arrow_use 3


#define lion 0
#define dragon 1
#define ninja 2
#define wolf 3
#define iceman 4

vector<string>color_name = { "red","blue" };
ofstream fout("魔兽输出");
int case_num;//测试数据组数
int red_energy = 0;//初始生命元
int blue_energy;
int red_num = 0;//编号
int blue_num;
int city_num = 0;//两个司令部之间一共有N个城市
int ATK_of_arrow = 0;//arrow的攻击力
int loss_of_loyalty = 0;
int end_time = 0;
int red_arrive = 0, blue_arrive = 0;//红色到达的 蓝色到达的
vector<string>red_warrior = { "iceman","lion","wolf","ninja","dragon" };
vector<string>blue_warrior = { "lion","dragon","ninja","iceman","wolf" };

struct weapons {
	int type;//0 sword 1 bomb 2 arrow 
	int ATK;//攻击力
	int time;//arrow的剩余使用次数
};

vector<string>weapon_name = { "sword","bomb","arrow" };

struct warrior {
	int color;//0 red 1 blue
	int type;
	int ID;//编号
	int HP;//health point 生命值
	int ATK;//attack攻击力
	double morale;
	int loyalty;
	vector<weapons>weapon;
	int place;//武士所在的城市
	bool escape;
	int living_condition;//0 没死 1 被射了  2 死了
};
int triumph[2] = { 7,13 };
struct city {
	int element;//生命元
	int flag;//0 无 1 red  2 blue
	int winner;//记录战斗的胜利者 红色赢+1 蓝色赢-1  2插红旗  -2插蓝旗
	vector<warrior*>warriors;//指向该城市有的武士的指针
};
vector<city>cities;

//初始血量值
vector<int>red_HP = { 0,0,0,0,0 };
vector<int>blue_HP = { 0,0,0,0,0 };

vector<int>red_ATK = { 0,0,0,0,0 };
vector<int>blue_ATK = { 0,0,0,0,0 };

vector<vector<warrior>>red;//第一维为各种武士 第二维为每种武士的每一个
vector<vector<warrior>>blue;//第一维为各种武士 第二维为每种武士的每一个

int type(warrior* p) {
	if (p->color == red_color && p->type == red_iceman)
		return iceman;
	if (p->color == blue_color && p->type == blue_iceman)
		return iceman;
	if (p->color == red_color && p->type == red_lion)
		return lion;
	if (p->color == blue_color && p->type == blue_lion)
		return lion;
	if (p->color == red_color && p->type == red_dragon)
		return dragon;
	if (p->color == blue_color && p->type == blue_dragon)
		return dragon;
	if (p->color == red_color && p->type == red_wolf)
		return wolf;
	if (p->color == blue_color && p->type == blue_wolf)
		return wolf;
	if (p->color == red_color && p->type == red_ninja)
		return ninja;
	if (p->color == blue_color && p->type == blue_ninja)
		return ninja;
}

void output_warrior(warrior* p) {//前后都没有空格
	if (p->color == red_color) {
		cout << "red " << red_warrior[p->type] << " " << p->ID;
	}
	if (p->color == blue_color) {
		cout << "blue " << blue_warrior[p->type] << " " << p->ID;
	}
}
void output_time(const int& hour, const int& min) {
	cout << setw(3) << setfill('0') << hour;
	cout << ":";
	cout << setw(2) << setfill('0') << min;
	cout << " ";
}
void input() {
	int life_energy;
	cin >> life_energy;//每个司令部一开始的生命元
	red_energy = life_energy;
	blue_energy = life_energy;

	cin >> city_num;//两个司令部之间一共有N个城市

	city temp;
	temp.element = 0;
	temp.flag = no_flag;//无旗子
	temp.winner = 0;
	for (int i = 0; i <= city_num + 1; i++) {
		cities.push_back(temp);
	}//城市初始化

	cin >> ATK_of_arrow;
	cin >> loss_of_loyalty;//lion每经历一场未杀死敌人的战斗 忠诚度就减少loss_of_loyalty
	cin >> end_time;//战争的结束时间

	/*第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000*/
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

	/*第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000*/
	int dragon_ATK;
	int ninja_ATK;
	int iceman_ATK;
	int lion_ATK;
	int wolf_ATK;

	cin >> dragon_ATK;
	cin >> ninja_ATK;
	cin >> iceman_ATK;
	cin >> lion_ATK;
	cin >> wolf_ATK;

	red_ATK[red_iceman] = iceman_ATK;
	red_ATK[red_lion] = lion_ATK;
	red_ATK[red_wolf] = wolf_ATK;
	red_ATK[red_ninja] = ninja_ATK;
	red_ATK[red_dragon] = dragon_ATK;

	blue_ATK[blue_iceman] = iceman_ATK;
	blue_ATK[blue_lion] = lion_ATK;
	blue_ATK[blue_wolf] = wolf_ATK;
	blue_ATK[blue_ninja] = ninja_ATK;
	blue_ATK[blue_dragon] = dragon_ATK;

}
void lose_weapon(warrior* p);
void warrior_born(const int& hour, const int& min, int& make_blue, int& make_red, int& red_energy, int& blue_energy) {


		

	int type = make_red % 5;
	if (red_energy >= red_HP[type]) {
		red_energy -= red_HP[type];//可以造人
		red_num++;
		make_red++;
		warrior temp;
		temp.place = red_headquarter;
		temp.ID = red_num;
		temp.HP = red_HP[type];
		temp.ATK = red_ATK[type];
		temp.color = red_color;
		temp.type = type;
		temp.living_condition = alive;
		if (type == red_dragon)
		{
			weapons w;
			w.type = red_num % 3;//龙获得武器
			if (w.type == sword)//武器的攻击力初始化
				w.ATK = (int)(0.2 * temp.ATK);
			if (w.type == arrow) {
				w.ATK = ATK_of_arrow;
				w.time = arrow_use;
			}
			temp.weapon.push_back(w);
			temp.morale = red_energy / red_HP[red_dragon];//龙的士气

		}

		if (type == red_iceman)
		{
			weapons w;
			w.type = red_num % 3;//雪人获得武器
			if (w.type == sword)//武器的攻击力初始化
				w.ATK = (int)(0.2 * temp.ATK);
			if (w.type == arrow) {
				w.ATK = ATK_of_arrow;
				w.time = arrow_use;
			}
			temp.weapon.push_back(w);
		}


		if (type == red_ninja)
		{
			weapons w1;
			w1.type = red_num % 3;//忍者获得武器
			weapons w2;
			w2.type = (red_num + 1) % 3;

			if (w1.type == sword)//武器的攻击力初始化
				w1.ATK = (int)((int)(0.2 * temp.ATK));
			if (w1.type == arrow) {
				w1.ATK = ATK_of_arrow;
				w1.time = arrow_use;
			}

			if (w2.type == sword)//武器的攻击力初始化
				w2.ATK = (int)((int)(0.2 * temp.ATK));
			if (w2.type == arrow) {
				w2.ATK = ATK_of_arrow;
				w2.time = arrow_use;
			}
			if (!(w1.type == sword && w1.ATK == 0))
				temp.weapon.push_back(w1);
			if (!(w2.type == sword && w2.ATK == 0))
				temp.weapon.push_back(w2);
		}

		if (type == red_lion) {
			int loy = red_energy;
			temp.loyalty = loy;//狮子的忠诚度
			temp.escape = false;
		}
		lose_weapon(&temp);
		red[type].push_back(temp);

		if (cities[city_num + 1].warriors.size() == 1)
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < red[i].size();j++) {
					if (red[i][j].place == city_num + 1)
						cities[city_num + 1].warriors[0] = &red[i][j];
			}
		
		warrior* p = &red[type][red[type].size() - 1];//指向刚刚产生的那个武士的地址
		cities[red_headquarter].warriors.push_back(p);
		output_time(hour, min);
		cout << "red " << red_warrior[type] << " " << red_num << " born" << endl;


		if (type == red_dragon) {
			cout << "Its morale is " << fixed << setprecision(2) << (double)red_energy / red_HP[red_dragon] << endl;
		}


		if (type == red_lion) {
			cout << "Its loyalty is " << red_energy << endl;
		}
	}
	//不够造 就啥也不干


	int type2 = make_blue % 5;
	if (blue_energy >= blue_HP[type2]) {
		blue_energy -= blue_HP[type2];//可以造雪人
		make_blue++;
		blue_num++;
		warrior temp;
		temp.place = blue_headquarter;
		temp.ID = blue_num;
		temp.HP = blue_HP[type2];
		temp.ATK = blue_ATK[type2];
		temp.color = blue_color;
		temp.type = type2;
		temp.living_condition = alive;
		if (type2 == blue_dragon)
		{
			weapons w;
			w.type = blue_num % 3;//龙获得武器
			if (w.type == sword)//武器的攻击力初始化
				w.ATK = (int)((int)(0.2 * temp.ATK));
			if (w.type == arrow) {
				w.ATK = ATK_of_arrow;
				w.time = arrow_use;
			}
			temp.weapon.push_back(w);
			temp.morale = blue_energy / blue_HP[blue_dragon];//龙的士气

		}

		if (type2 == blue_iceman)
		{
			weapons w;
			w.type = blue_num % 3;//雪人获得武器
			if (w.type == sword)//武器的攻击力初始化
				w.ATK = (int)((int)(0.2 * temp.ATK));
			if (w.type == arrow) {
				w.ATK = ATK_of_arrow;
				w.time = arrow_use;
			}
			temp.weapon.push_back(w);
		}


		if (type2 == blue_ninja)
		{
			weapons w1;
			w1.type = blue_num % 3;//忍者获得武器
			weapons w2;
			w2.type = (blue_num + 1) % 3;

			if (w1.type == sword)//武器的攻击力初始化
				w1.ATK = (int)(0.2 * temp.ATK);
			if (w1.type == arrow) {
				w1.ATK = ATK_of_arrow;
				w1.time = arrow_use;
			}

			if (w2.type == sword)//武器的攻击力初始化
				w2.ATK = (int)(0.2 * temp.ATK);
			if (w2.type == arrow) {
				w2.ATK = ATK_of_arrow;
				w2.time = arrow_use;
			}
			temp.weapon.push_back(w1);
			temp.weapon.push_back(w2);
		}

		if (type2 == blue_lion) {
			int loy = blue_energy;
			temp.loyalty = loy;//狮子的忠诚度
			temp.escape = false;
		}


		lose_weapon(&temp);
		blue[type2].push_back(temp);
		if (cities[0].warriors.size() == 1)
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < blue[i].size();j++) {
					if (blue[i][j].place == 0)
						cities[0].warriors[0] = &blue[i][j];
				}
		
		warrior* p = &blue[type2][blue[type2].size() - 1];//指向刚刚产生的那个武士的地址
		cities[blue_headquarter].warriors.push_back(p);
		output_time(hour, min);
		cout << "blue " << blue_warrior[type2] << " " << blue_num << " born" << endl;

		if (type2 == blue_dragon) {
			cout << "Its morale is " << fixed << setprecision(2) << (double)blue_energy / blue_HP[blue_dragon] << endl;
		}

		if (type2 == blue_lion) {
			cout << "Its loyalty is " << blue_energy << endl;
		}




	}

}
void lion_escape(const int& hour, const int& min) {

	for (int i = 0; i <= city_num + 1; i++) {
		vector<warrior*>::iterator iter;
		for (iter = cities[i].warriors.begin(); iter != cities[i].warriors.end();) {
			if ((((*iter)->type == red_lion && (*iter)->color == red_color) || ((*iter)->type == blue_lion && (*iter)->color == blue_color)) && (*iter)->loyalty <= 0) {
				output_time(hour, min);
				cout << color_name[(*iter)->color] << " lion " << (*iter)->ID << " ran away" << endl;
				(*iter)->living_condition = dead;//下一波走的时候就不管它
				iter = cities[i].warriors.erase(iter);
			}
			else
				iter++;
		}
	}
}
void judge_occupy(const int& hour, const int& min, int c) {

	if (blue_arrive == 2 && c == blue_color) {
		output_time(hour, min);
		cout << "red headquarter was taken" << endl;

	}
	if (red_arrive == 2 && c == red_color) {
		output_time(hour, min);
		cout << "blue headquarter was taken" << endl;

	}
}
void warrior_walk(const int& hour, const int& min) {
	warrior* p1 = NULL;
	for (int j = 0; j < cities[0].warriors.size(); j++) {
		if (cities[0].warriors[j]->color == blue_color)
			p1 = cities[0].warriors[j];
	}

	warrior* p2 = NULL;
	for (int j = 0; j < cities[city_num + 1].warriors.size(); j++) {
		if (cities[city_num + 1].warriors[j]->color == red_color)
			p2 = cities[city_num + 1].warriors[j];
	}

	for (int i = 0; i <= city_num + 1; i++)//city的指针全部清空 走完之后重设 
		cities[i].warriors.clear();

	if (p1 != NULL)
		cities[0].warriors.push_back(p1);
	if (p2 != NULL)
		cities[city_num + 1].warriors.push_back(p2);

	for (int i = 0; i < red.size(); i++) {
		for (int j = 0; j < red[i].size(); j++) {
			if (red[i][j].living_condition == alive) {
				//只对活着的进行操作
				red[i][j].place++;//红武士前进
				if (i == red_iceman) {
					if (abs(red[i][j].place - red_headquarter) % 2 == 0) {
						//每走两步掉血
						red[i][j].HP -= loss_HP;
						if (red[i][j].HP <= 0)
							red[i][j].HP = 1;
						red[i][j].ATK += add_ATK;
					}
				}


				if (red[i][j].place == blue_headquarter) {
					red_arrive++;
					red[i][j].living_condition = dying;//到了 就当他濒死 以表示这一波刚到

				}
				warrior* p = &red[i][j];
				cities[red[i][j].place].warriors.push_back(p);


			}
		}
	}


	for (int i = 0; i < blue.size(); i++) {
		for (int j = 0; j < blue[i].size(); j++) {
			if (blue[i][j].living_condition == alive) {
				blue[i][j].place--;//蓝武士前进

				if (i == blue_iceman) {
					if (abs(blue_headquarter - blue[i][j].place) % 2 == 0) {
						blue[i][j].HP -= loss_HP;
						if (blue[i][j].HP <= 0)
							blue[i][j].HP = 1;
						blue[i][j].ATK += add_ATK;
					}
				}

				if (blue[i][j].place == red_headquarter) {
					blue_arrive++;
					blue[i][j].living_condition = dying;
				}

				warrior* p = &blue[i][j];
				cities[blue[i][j].place].warriors.push_back(p);


			}
		}
	}

	//按照城市打印输出
	for (int i = 0; i <= city_num + 1; i++) {//第i个城市 
		for (int j = 0; j < cities[i].warriors.size(); j++) {//j是第i个城市的第j个武士


			if (cities[i].warriors[j]->color == red_color) {
				if (i == city_num + 1)
				{
					if (cities[i].warriors[j]->living_condition == dying) {
						output_time(hour, min);
						output_warrior(cities[i].warriors[j]); cout << " reached blue headquarter with " << cities[i].warriors[j]->HP << " elements and force " << cities[i].warriors[j]->ATK << endl;
						judge_occupy(hour, min, red_color);
					}
					continue;
				}
				output_time(hour, min);
				cout << color_name[cities[i].warriors[j]->color] << " " << red_warrior[cities[i].warriors[j]->type] << " " << cities[i].warriors[j]->ID;
				cout << " marched to city " << i << " with " << cities[i].warriors[j]->HP << " elements and force " << cities[i].warriors[j]->ATK << endl;
				//输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
			}
			if (cities[i].warriors[j]->color == blue_color) {
				if (i == 0)
				{
					if (cities[i].warriors[j]->living_condition == dying) {
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]); cout << " reached red headquarter with " << cities[i].warriors[j]->HP << " elements and force " << cities[i].warriors[j]->ATK << endl;
						judge_occupy(hour, min, blue_color);
					}
					continue;
				}
				output_time(hour, min);
				cout << color_name[cities[i].warriors[j]->color] << " " << blue_warrior[cities[i].warriors[j]->type] << " " << cities[i].warriors[j]->ID;
				cout << " marched to city " << i << " with " << cities[i].warriors[j]->HP << " elements and force " << cities[i].warriors[j]->ATK << endl;
			}
		}
	}


	for (int j = 0; j < cities[0].warriors.size(); j++)
		if (cities[0].warriors[j]->living_condition == dying)
			cities[0].warriors[j]->living_condition = dead;
	for (int j = 0; j < cities[city_num + 1].warriors.size(); j++)
		if (cities[city_num + 1].warriors[j]->living_condition == dying)
			cities[city_num + 1].warriors[j]->living_condition = dead;

}
void lose_weapon(warrior* p) {
	vector<weapons>::iterator iter;
	for (iter = p->weapon.begin(); iter != p->weapon.end(); ) {
		if ((iter->type == sword && iter->ATK <= 0) || (iter->type == arrow && iter->time <= 0))
			iter = p->weapon.erase(iter);
		else
			iter++;
	}
}
void city_create_elements() {
	for (int i = 1; i <= city_num; i++) {
		cities[i].element += 10;
	}
}
void pick_up_elements(const int& hour, const int& min) {
	for (int i = 1; i <= city_num; i++) {
		if (cities[i].warriors.size() == 1) {
			if (cities[i].warriors[0]->color == red_color) {
				red_energy += cities[i].element;//取走能量元
				output_time(hour, min);
				output_warrior(cities[i].warriors[0]);
				cout << " earned " << cities[i].element << " elements for his headquarter" << endl;
				cities[i].element = 0;

			}
			if (cities[i].warriors[0]->color == blue_color) {
				blue_energy += cities[i].element;//取走能量元
				output_time(hour, min);
				output_warrior(cities[i].warriors[0]);
				cout << " earned " << cities[i].element << " elements for his headquarter" << endl;
				cities[i].element = 0;
			}
		}
	}
}
void warrior_shot(const int& hour) {

	for (int i = 1; i <= city_num; i++) {//i号城  从1到N号城看有没有人放箭
		for (int j = 0; j < cities[i].warriors.size(); j++) { //i号城的第j个武士
			for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++)//i号城的第j个武士的第k个武器
				if (cities[i].warriors[j]->weapon[k].type == arrow && cities[i].warriors[j]->weapon[k].time > 0) {//有arrow并且还能射
					if (cities[i].warriors[j]->color == red_color) {
						//如果是红武士
						if ((i + 1) == blue_headquarter)
							continue;//如果下一座是蓝色总部 就不操作
						for (int g = 0; g < cities[i + 1].warriors.size(); g++) {
							//看下一座城有没有蓝武士可以射 
							if (cities[i + 1].warriors[g]->color == blue_color && cities[i + 1].warriors[g]->living_condition != dead) {
								cities[i + 1].warriors[g]->HP -= ATK_of_arrow;//没死就射他
								cities[i].warriors[j]->weapon[k].time--;
								lose_weapon(cities[i].warriors[j]);

								cout << setw(3) << setfill('0') << hour;
								cout << ":35 ";
								output_warrior(cities[i].warriors[j]);
								cout << " shot";

								if (cities[i + 1].warriors[g]->HP <= 0) {
									cities[i + 1].warriors[g]->living_condition = dying;//濒死 即已经死了 但还可以在这一波射别人
									cout << " and killed ";
									output_warrior(cities[i + 1].warriors[g]);
								}
								cout << endl;
							}
						}
					}

					if (cities[i].warriors[j]->color == blue_color) {
						//如果是蓝武士
						if ((i - 1) == red_headquarter)
							continue;
						for (int g = 0; g < cities[i - 1].warriors.size(); g++) {
							//看下一座城有没有蓝武士可以射 
							if (cities[i - 1].warriors[g]->color == red_color && cities[i - 1].warriors[g]->living_condition != dead) {
								cities[i - 1].warriors[g]->HP -= ATK_of_arrow;//没死就射他
								cities[i].warriors[j]->weapon[k].time--;
								lose_weapon(cities[i].warriors[j]);

								cout << setw(3) << setfill('0') << hour;
								cout << ":35 ";
								output_warrior(cities[i].warriors[j]);
								cout << " shot";
								if (cities[i - 1].warriors[g]->HP <= 0) {
									cities[i - 1].warriors[g]->living_condition = dying;//濒死 即已经死了 但还可以在这一波射别人
									cout << " and killed ";
									output_warrior(cities[i - 1].warriors[g]);
								}
								cout << endl;
							}
						}
					}
				}
		}

	}


	//全都射完了 濒死的都死了
	for (int i = 1; i <= city_num; i++) {
		for (int j = 0; j < cities[i].warriors.size(); j++) {
			if (cities[i].warriors[j]->living_condition == dying) {
				cities[i].warriors[j]->living_condition = dead;
			}
		}
	}
}

void headquarter_annouce_element(const int& hour, const int& min) {
	output_time(hour, min);
	cout << red_energy << " elements in red headquarter" << endl;
	output_time(hour, min);
	cout << blue_energy << " elements in blue headquarter" << endl;
}

int first_fight(int i) {//i号城
	if (cities[i].flag == red_flag)//在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。
		return red_first;
	if (cities[i].flag == blue_flag)//在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。
		return blue_first;
	if (cities[i].flag == no_flag)
	{
		if (i % 2 == 1)
			return red_first;
		if (i % 2 == 0)
			return blue_first;

	}

}

void acquire_elements(const int& hour, const int& min, int i, warrior* p) {
	output_time(hour, min);
	output_warrior(p);
	cout << " earned " << cities[i].element << " elements for his headquarter" << endl;
	if (p->color == red_color) {
		red_energy += cities[i].element;
	}
	if (p->color == blue_color) {
		blue_energy += cities[i].element;
	}
	cities[i].element = 0;
}
int has_sword(warrior* p) {
	for (int i = 0; i < p->weapon.size(); i++) {
		if (p->weapon[i].type == sword)
			return p->weapon[i].ATK;//
	}
	return 0;//
}
void sword_dull(warrior* p) {
	for (int i = 0; i < p->weapon.size(); i++) {
		if (p->weapon[i].type == sword) {
			p->weapon[i].ATK = (int)(0.8 * p->weapon[i].ATK);
		}
	}
}
int judge_winner(int i) {
	//如果city i发生战斗 找出赢家
	if (cities[i].warriors.size() < 2)
		return draw;//不发生战斗 但在这里看成是平局 最后的效果是不给它发血量
	for (int j = 0; j < 2; j++) {
		if (cities[i].warriors[j]->living_condition == dead && cities[i].warriors[1 - j]->living_condition == alive)
			return cities[i].warriors[1 - j]->color;
	}
	if (cities[i].warriors[0]->living_condition == dead && cities[i].warriors[1]->living_condition == dead)
		return draw;//都被射死了 虽然没有发生战斗 但在这里看成是平局
	for (int j = 0; j < 2; j++) {
		if (cities[i].warriors[j]->type == first_fight(i)) {//先手
			if (has_sword(cities[i].warriors[j]) + cities[i].warriors[j]->ATK >= cities[i].warriors[1 - j]->HP) {
				return cities[i].warriors[j]->color;
			}
		}
	}
	for (int j = 0; j < 2; j++) {
		if (cities[i].warriors[j]->type != first_fight(i)) {//后手
			if (has_sword(cities[i].warriors[j]) + (int)(0.5 * cities[i].warriors[j]->ATK) >= cities[i].warriors[1 - j]->HP) {
				return cities[i].warriors[j]->color;
			}
		}
	}
	return draw;//平局
}
void use_bomb(const int& hour, const int& min) {
	for (int i = 1; i <= city_num; i++) {
		if (cities[i].warriors.size() == 2) {
			for (int j = 0; j < 2; j++) {
				if (cities[i].warriors[j]->living_condition == dead || cities[i].warriors[1 - j]->living_condition == dead)
					continue;
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == bomb)//i号城 j号武士 k号武器
					{
						if (cities[i].warriors[j]->color == first_fight(i)) {//先手
							if (has_sword(cities[i].warriors[j]) + cities[i].warriors[j]->ATK >= cities[i].warriors[1 - j]->HP)
								break;//如果能杀死对手
							if (type(cities[i].warriors[1 - j]) == ninja)//对方是忍者 不还手 不造成威胁
								break;
							if (cities[i].warriors[j]->HP <= has_sword(cities[i].warriors[1 - j]) + (int)(cities[i].warriors[1 - j]->ATK * 0.5)) {
								cities[i].warriors[j]->living_condition = dead;//预判到自己要死了
								cities[i].warriors[1 - j]->living_condition = dead;
								output_time(hour, min);
								output_warrior(cities[i].warriors[j]);
								cout << " used a bomb and killed ";
								output_warrior(cities[i].warriors[1 - j]);
								cout << endl;
								break;
							}

						}
						if (cities[i].warriors[j]->color != first_fight(i)) {
							if (cities[i].warriors[j]->HP <= has_sword(cities[i].warriors[1 - j]) + cities[i].warriors[1 - j]->ATK) {
								//使用炸弹 同归于尽
								cities[i].warriors[j]->living_condition = dead;
								cities[i].warriors[1 - j]->living_condition = dead;
								output_time(hour, min);
								output_warrior(cities[i].warriors[j]);
								cout << " used a bomb and killed ";
								output_warrior(cities[i].warriors[1 - j]);
								cout << endl;
								break;
							}
						}
					}
				}
			}
		}
	}
}
void deliver_element(int i, warrior* p) {
	if (p->color == red_color) {
		if (red_energy >= 8)
		{
			p->HP += 8;
			red_energy -= 8;
			return;
		}
		if (red_energy < 8) {
			p->HP += red_energy;
			red_energy = 0;
			return;
		}
	}
	if (p->color == blue_color) {
		int sum_element = blue_energy;
		for (int k = city_num; k > i; k--) {//从东往西遍历  先把i号城东边的假装发一下
			if (judge_winner(k) == blue_color)
				sum_element -= 8;
		}
		if (sum_element >= 8) {
			p->HP += 8;
			blue_energy -= 8;
		}
		if (sum_element > 0 && sum_element < 8) {
			p->HP += blue_energy;
			blue_energy = 0;
		}
		if (sum_element <= 0) {
			//看来发不到这座城了
		}
	}
}
void annouce_weapon(const int& hour, const int& min) {
	//红司令部的人报告
	for (int j = 0; j < cities[0].warriors.size(); j++) {
		if (cities[0].warriors[j]->color == blue_color)
			continue;
		if (cities[0].warriors[j]->weapon.size() == 0) {
			output_time(hour, min);
			output_warrior(cities[0].warriors[j]);
			cout << " has no weapon" << endl;
		}
		else {
			bool f = false;
			for (int k = 0; k < cities[0].warriors[j]->weapon.size(); k++) {
				if (cities[0].warriors[j]->weapon[k].type == arrow) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]);
						cout << " has arrow(" << cities[0].warriors[j]->weapon[k].time << ")";
					}
					else
					{
						cout << ",arrow(" << cities[0].warriors[j]->weapon[k].time << ")";
					}
				}
			}
			for (int k = 0; k < cities[0].warriors[j]->weapon.size(); k++) {
				if (cities[0].warriors[j]->weapon[k].type == bomb) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]);
						cout << " has bomb";
					}
					else
					{
						cout << ",bomb";
					}
				}
			}
			for (int k = 0; k < cities[0].warriors[j]->weapon.size(); k++) {
				if (cities[0].warriors[j]->weapon[k].type == sword) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]);
						cout << " has sword(" << cities[0].warriors[j]->weapon[k].ATK << ")";
					}
					else
					{
						cout << ",sword(" << cities[0].warriors[j]->weapon[k].ATK << ")";
					}
				}
			}
			cout << endl;
		}
	}


	for (int i = 1; i <= city_num; i++) {
		for (int j = 0; j < cities[i].warriors.size(); j++) {
			if (cities[i].warriors[j]->color == blue_color)
				continue;
			if (cities[i].warriors[j]->living_condition == dead)
				continue;
			if (cities[i].warriors[j]->weapon.size() == 0) {
				output_time(hour, min);
				output_warrior(cities[i].warriors[j]);
				cout << " has no weapon" << endl;
			}
			else {
				bool f = false;
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == arrow) {
						if (!f) {
							f = true;
							output_time(hour, min);
							output_warrior(cities[i].warriors[j]);
							cout << " has arrow(" << cities[i].warriors[j]->weapon[k].time << ")";
						}
						else
						{
							cout << ",arrow(" << cities[i].warriors[j]->weapon[k].time << ")";
						}
					}
				}
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == bomb) {
						if (!f) {
							f = true;
							output_time(hour, min);
							output_warrior(cities[i].warriors[j]);
							cout << " has bomb";
						}
						else
						{
							cout << ",bomb";
						}
					}
				}
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == sword) {
						if (!f) {
							f = true;
							output_time(hour, min);
							output_warrior(cities[i].warriors[j]);
							cout << " has sword(" << cities[i].warriors[j]->weapon[k].ATK << ")";
						}
						else
						{
							cout << ",sword(" << cities[i].warriors[j]->weapon[k].ATK << ")";
						}
					}
				}
				cout << endl;
			}
		}
	}

	for (int j = 0; j < cities[blue_headquarter].warriors.size(); j++) {
		if (cities[blue_headquarter].warriors[j]->color == blue_color)
			continue;
		if (cities[blue_headquarter].warriors[j]->weapon.size() == 0) {
			output_time(hour, min);
			output_warrior(cities[blue_headquarter].warriors[j]);
			cout << " has no weapon" << endl;
		}
		else {
			bool f = false;
			for (int k = 0; k < cities[blue_headquarter].warriors[j]->weapon.size(); k++) {
				if (cities[blue_headquarter].warriors[j]->weapon[k].type == arrow) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[blue_headquarter].warriors[j]);
						cout << " has arrow(" << cities[blue_headquarter].warriors[j]->weapon[k].time << ")";
					}
					else
					{
						cout << ",arrow(" << cities[blue_headquarter].warriors[j]->weapon[k].time << ")";
					}
				}
			}
			for (int k = 0; k < cities[blue_headquarter].warriors[j]->weapon.size(); k++) {
				if (cities[blue_headquarter].warriors[j]->weapon[k].type == bomb) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[blue_headquarter].warriors[j]);
						cout << " has bomb";
					}
					else
					{
						cout << ",bomb";
					}
				}
			}
			for (int k = 0; k < cities[blue_headquarter].warriors[j]->weapon.size(); k++) {
				if (cities[blue_headquarter].warriors[j]->weapon[k].type == sword) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[blue_headquarter].warriors[j]);
						cout << " has sword(" << cities[blue_headquarter].warriors[j]->weapon[k].ATK << ")";
					}
					else
					{
						cout << ",sword(" << cities[blue_headquarter].warriors[j]->weapon[k].ATK << ")";
					}
				}
			}
			cout << endl;
		}
	}



	//蓝司令部的人报告
	for (int j = 0; j < cities[0].warriors.size(); j++) {
		if (cities[0].warriors[j]->color == red_color)
			continue;
		if (cities[0].warriors[j]->weapon.size() == 0) {
			output_time(hour, min);
			output_warrior(cities[0].warriors[j]);
			cout << " has no weapon" << endl;
		}
		else {
			bool f = false;
			for (int k = 0; k < cities[0].warriors[j]->weapon.size(); k++) {
				if (cities[0].warriors[j]->weapon[k].type == arrow) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]);
						cout << " has arrow(" << cities[0].warriors[j]->weapon[k].time << ")";
					}
					else
					{
						cout << ",arrow(" << cities[0].warriors[j]->weapon[k].time << ")";
					}
				}
			}
			for (int k = 0; k < cities[0].warriors[j]->weapon.size(); k++) {
				if (cities[0].warriors[j]->weapon[k].type == bomb) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]);
						cout << " has bomb";
					}
					else
					{
						cout << ",bomb";
					}
				}
			}
			for (int k = 0; k < cities[0].warriors[j]->weapon.size(); k++) {
				if (cities[0].warriors[j]->weapon[k].type == sword) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[0].warriors[j]);
						cout << " has sword(" << cities[0].warriors[j]->weapon[k].ATK << ")";
					}
					else
					{
						cout << ",sword(" << cities[0].warriors[j]->weapon[k].ATK << ")";
					}
				}
			}
			cout << endl;
		}
	}


	for (int i = 1; i <= city_num; i++) {
		for (int j = 0; j < cities[i].warriors.size(); j++) {
			if (cities[i].warriors[j]->color == red_color)
				continue;
			if (cities[i].warriors[j]->living_condition == dead)
				continue;
			if (cities[i].warriors[j]->weapon.size() == 0) {
				output_time(hour, min);
				output_warrior(cities[i].warriors[j]);
				cout << " has no weapon" << endl;
			}
			else {
				bool f = false;
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == arrow) {
						if (!f) {
							f = true;
							output_time(hour, min);
							output_warrior(cities[i].warriors[j]);
							cout << " has arrow(" << cities[i].warriors[j]->weapon[k].time << ")";
						}
						else
						{
							cout << ",arrow(" << cities[i].warriors[j]->weapon[k].time << ")";
						}
					}
				}
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == bomb) {
						if (!f) {
							f = true;
							output_time(hour, min);
							output_warrior(cities[i].warriors[j]);
							cout << " has bomb";
						}
						else
						{
							cout << ",bomb";
						}
					}
				}
				for (int k = 0; k < cities[i].warriors[j]->weapon.size(); k++) {
					if (cities[i].warriors[j]->weapon[k].type == sword) {
						if (!f) {
							f = true;
							output_time(hour, min);
							output_warrior(cities[i].warriors[j]);
							cout << " has sword(" << cities[i].warriors[j]->weapon[k].ATK << ")";
						}
						else
						{
							cout << ",sword(" << cities[i].warriors[j]->weapon[k].ATK << ")";
						}
					}
				}
				cout << endl;
			}
		}
	}

	for (int j = 0; j < cities[blue_headquarter].warriors.size(); j++) {
		if (cities[blue_headquarter].warriors[j]->color == red_color)
			continue;
		if (cities[blue_headquarter].warriors[j]->weapon.size() == 0) {
			output_time(hour, min);
			output_warrior(cities[blue_headquarter].warriors[j]);
			cout << " has no weapon" << endl;
		}
		else {
			bool f = false;
			for (int k = 0; k < cities[blue_headquarter].warriors[j]->weapon.size(); k++) {
				if (cities[blue_headquarter].warriors[j]->weapon[k].type == arrow) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[blue_headquarter].warriors[j]);
						cout << " has arrow(" << cities[blue_headquarter].warriors[j]->weapon[k].time << ")";
					}
					else
					{
						cout << ",arrow(" << cities[blue_headquarter].warriors[j]->weapon[k].time << ")";
					}
				}
			}
			for (int k = 0; k < cities[blue_headquarter].warriors[j]->weapon.size(); k++) {
				if (cities[blue_headquarter].warriors[j]->weapon[k].type == bomb) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[blue_headquarter].warriors[j]);
						cout << " has bomb";
					}
					else
					{
						cout << ",bomb";
					}
				}
			}
			for (int k = 0; k < cities[blue_headquarter].warriors[j]->weapon.size(); k++) {
				if (cities[blue_headquarter].warriors[j]->weapon[k].type == sword) {
					if (!f) {
						f = true;
						output_time(hour, min);
						output_warrior(cities[blue_headquarter].warriors[j]);
						cout << " has sword(" << cities[blue_headquarter].warriors[j]->weapon[k].ATK << ")";
					}
					else
					{
						cout << ",sword(" << cities[blue_headquarter].warriors[j]->weapon[k].ATK << ")";
					}
				}
			}
			cout << endl;
		}
	}
}

void change_flag(const int& hour, const int& min, int i, warrior* p) {//i号城胜利的武士

	if (cities[i].flag == p->color) {
		cities[i].winner = 0;
	}
	if (cities[i].flag != no_flag && cities[i].flag != p->color) {//如果是对手的旗子
		if (cities[i].winner == triumph[p->color])
			cities[i].winner += triumph[p->color];
		else
			cities[i].winner = triumph[p->color];
		if (cities[i].winner == 2 * triumph[p->color]) {//换旗子
			cities[i].flag = p->color;
			cities[i].winner = 0;
			output_time(hour, min);
			cout << color_name[p->color] << " flag raised in city " << i << endl;
		}
	}
	if (cities[i].flag == no_flag) {
		if (cities[i].winner == triumph[p->color])
			cities[i].winner += triumph[p->color];
		else
			cities[i].winner = triumph[p->color];
		if (cities[i].winner == 2 * triumph[p->color]) {//换旗子
			cities[i].flag = p->color;
			cities[i].winner = 0;
			output_time(hour, min);
			cout << color_name[p->color] << " flag raised in city " << i << endl;
		}
	}

}
void wolf_gain(warrior* p, warrior* q) {
	bool has_sword = false;
	bool has_bomb = false;
	bool has_arrow = false;
	for (int i = 0; i < p->weapon.size(); i++) {
		if (p->weapon[i].type == sword)
			has_sword = true;
		if (p->weapon[i].type == arrow)
			has_arrow = true;
		if (p->weapon[i].type == bomb)
			has_bomb = true;
	}
	for (int i = 0; i < q->weapon.size(); i++) {
		if (q->weapon[i].type == sword && !has_sword)
			p->weapon.push_back(q->weapon[i]);
		if (q->weapon[i].type == arrow && !has_arrow)
			p->weapon.push_back(q->weapon[i]);
		if (q->weapon[i].type == bomb && !has_bomb)
			p->weapon.push_back(q->weapon[i]);
	}
}
void fight(const int& hour, const int& min) {
	for (int i = 1; i <= city_num; i++) {
		if (cities[i].warriors.size() == 2) {
			warrior* vic = NULL;//指向胜利的一方
			warrior* def = NULL;//指向失败的一方
			if (cities[i].warriors[0]->living_condition == alive && cities[i].warriors[1]->living_condition == alive) {//如果该城有两活人 战斗

				//先让先手打
				for (int j = 0; j < cities[i].warriors.size(); j++) {//i城的j号武士  那么另一个就是第（1-j）号武士

					if (cities[i].warriors[j]->color == first_fight(i) && cities[i].warriors[j]->living_condition == alive) {
						//发起进攻


						int before_HP = cities[i].warriors[1 - j]->HP;// 被打前的HP 

						cities[i].warriors[1 - j]->HP -= has_sword(cities[i].warriors[j]) + cities[i].warriors[j]->ATK;
						sword_dull(cities[i].warriors[j]);
						lose_weapon(cities[i].warriors[j]);



						output_time(hour, min);
						output_warrior(cities[i].warriors[j]);
						cout << " attacked ";
						output_warrior(cities[i].warriors[1 - j]);
						cout << " in city " << i << " with " << cities[i].warriors[j]->HP << " elements and force " << cities[i].warriors[j]->ATK << endl;


						if (cities[i].warriors[1 - j]->HP <= 0) {
							cities[i].warriors[1 - j]->living_condition = dead;
							output_time(hour, min);
							output_warrior(cities[i].warriors[1 - j]);
							cout << " was killed in city " << i << endl;

							vic = cities[i].warriors[j];
							def = cities[i].warriors[1 - j];
						}
						if (def!=NULL&&type(def) == lion) {
							//如果杀死的是狮子
							cities[i].warriors[j]->HP += before_HP;
						}

					}

				}//先手打完了

				//后手打
				for (int j = 0; j < cities[i].warriors.size(); j++) {
					//反击
					if (cities[i].warriors[j]->color != first_fight(i) && cities[i].warriors[j]->living_condition == alive) {

						if (type(cities[i].warriors[j]) == ninja)
							break;//忍者不还手 

						if (cities[i].warriors[1 - j]->HP - (has_sword(cities[i].warriors[j]) + (int)(0.5 * cities[i].warriors[j]->ATK)) <= 0 && type(cities[i].warriors[1 - j]) == lion) {
							//如果杀死的是狮子
							cities[i].warriors[j]->HP += cities[i].warriors[1 - j]->HP;
						}
						cities[i].warriors[1 - j]->HP -= has_sword(cities[i].warriors[j]) + (int)(0.5 * (cities[i].warriors[j]->ATK));
						sword_dull(cities[i].warriors[j]);
						lose_weapon(cities[i].warriors[j]);

						output_time(hour, min);
						output_warrior(cities[i].warriors[j]);
						cout << " fought back against ";
						output_warrior(cities[i].warriors[1 - j]);
						cout << " in city " << i << endl;
						if (cities[i].warriors[1 - j]->HP <= 0) {
							cities[i].warriors[1 - j]->living_condition = dead;
							output_time(hour, min);
							output_warrior(cities[i].warriors[1 - j]);
							cout << " was killed in city " << i << endl;

							vic = cities[i].warriors[j];
							def = cities[i].warriors[1 - j];
						}
					}

				}
			}//后手打完了
			bool arrow_or_bomb = false;
			//收拾战局  活着的人是赢家 包括对方被射死
			for (int j = 0; j < 2; j++) {
				if (cities[i].warriors[j]->living_condition == alive && cities[i].warriors[1 - j]->living_condition == dead)
				{
					vic = cities[i].warriors[j];
					def = cities[i].warriors[1 - j];
				}
				if (cities[i].warriors[j]->living_condition == dead && cities[i].warriors[1 - j]->living_condition == dead) {
					//都被arrow射死或者被bomb炸死
					arrow_or_bomb = true;
				}
			}
			for (int j = 0; j < 2; j++) {//狮子
				if (type(cities[i].warriors[j]) == lion && cities[i].warriors[j]->living_condition == alive) {
					if (cities[i].warriors[1 - j]->living_condition == alive)
						cities[i].warriors[j]->loyalty -= loss_of_loyalty;
				}
			}

			if (vic != NULL)
			{
				if (type(vic) == wolf)
					wolf_gain(vic, def);

				if (type(vic) == dragon)
					vic->morale += 0.2;
				deliver_element(i, vic);

				for (int j = 0; j < 2; j++) {//龙
					if (first_fight(i) == cities[i].warriors[j]->color && type(cities[i].warriors[j]) == dragon && cities[i].warriors[j]->living_condition == alive && cities[i].warriors[j]->morale > 0.8) {
						output_time(hour, min);
						output_warrior(cities[i].warriors[j]);
						cout << " yelled in city " << i << endl;
					}
				}

				acquire_elements(hour, min, i, vic);
				change_flag(hour, min, i, vic);


			}
			if (vic == NULL) {
				for (int j = 0; j < 2; j++) {
					if (type(cities[i].warriors[j]) == dragon)
						cities[i].warriors[j]->morale -= 0.2;
				}
				for (int j = 0; j < 2; j++) {//龙
					if (first_fight(i) == cities[i].warriors[j]->color && type(cities[i].warriors[j]) == dragon && cities[i].warriors[j]->living_condition == alive && cities[i].warriors[j]->morale > 0.8) {
						output_time(hour, min);
						output_warrior(cities[i].warriors[j]);
						cout << " yelled in city " << i << endl;
					}
				}
				if (!arrow_or_bomb)
					cities[i].winner = 0;
			}

		}
	}
}
int main() {
	cin >> case_num;

	for (int i = 1; i <= case_num; i++) {
		red.clear();
		blue.clear();
		cities.clear();

		vector<warrior>temps;
		for (int j = 0; j < 5; j++) {
			red.push_back(temps);
			blue.push_back(temps);
		}

		input();

		cout << "Case " << i << ":" << endl;
		int hour = 0;//时
		int min = 0;//分


		int make_blue = hour;
		int make_red = hour;

		red_num = 0;
		blue_num = 0;

		red_arrive = 0;
		blue_arrive = 0;

		while (1) {
			//在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。
			warrior_born(hour, min, make_blue, make_red, red_energy, blue_energy);
			min += 5;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了
			lion_escape(hour, min);
			min += 5;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。
			warrior_walk(hour, min);
			if (red_arrive == 2 || blue_arrive == 2)
				break;
			min += 10;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。
			city_create_elements();
			min += 10;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，
			//并立即将这些生命元传送到其所属的司令部
			pick_up_elements(hour, min);
			min += 5;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第35分，拥有arrow的武士放箭，对敌人造成伤害。放箭事件应算发生在箭发出的城市。
			warrior_shot(hour);
			min += 3;
			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。
			use_bomb(hour, min);
			min += 2;
			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第40分：在有两个武士的城市，会发生战斗。
			fight(hour, min);
			min += 10;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第50分，司令部报告它拥有的生命元数量。
			headquarter_annouce_element(hour, min);
			min += 5;

			if (hour * 60 + min > end_time)
				break;
			//在每个小时的第55分，每个武士报告其拥有的武器情况
			annouce_weapon(hour, min);
			min = 0;
			hour++;

			if (hour * 60 + min > end_time)
				break;
		}

	}
	return 0;
}
