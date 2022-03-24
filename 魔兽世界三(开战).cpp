#define blue N+1
#define red 0

#define Iceman 0
#define Lion 1
#define Wolf 2
#define Ninja 3
#define Dragon 4

#define Sword 0
#define Bomb 1
#define Arrow 2

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<sstream>
using namespace std;
ofstream fout("myfile.txt");
int Time = 0;//现在的时间 即离开始过去了多少分钟
string name[5] = { "iceman","lion","wolf","ninja","dragon" };
string weapon_name[3] = { "sword","bomb","arrow" };
string color_name[30];
int ID[30];
int M = 0, N = 0, K = 0, T = 0;
int ele[5];
int ATK[5];
class warrior;
class city;
void print_time() {
	int hour = Time / 60;
	int min = Time % 60;
	cout << setfill('0') << setw(3) << hour << ":" << setw(2) << min<<" ";
}
void gain_weapon(warrior*w1,int wtype,int used);
string color_type_id(warrior* w);

class weapon {
private:
	
public:
	int ATK;//武器的攻击力
	int used;
	weapon() {
		ATK = 0;
		used = 0;
	}
	weapon(int a) {
		ATK = a;
		used = 0;
	}
	void set_ATK(int a) {
		ATK = a;
	}
	virtual void attack(warrior* w1, warrior* w2);
};
class sword :public weapon{
public:
	sword() {	}
	sword(int a):weapon(a) {	}

};
class bomb :public weapon {
public:
	bomb(){ }
	bomb(int a):weapon(a){    }
	void attack(warrior* w1, warrior* w2);
		

};
class arrow :public weapon {
public:
	arrow(){ }
	arrow(int a) :weapon(a) { used = 0; }
	void attack(warrior* w1, warrior* w2);
		
};
class city {
public:
	int element;//生命元
	warrior* p[2];//该城市的武士 0是red的 1是blue的

	int its_element() {//某城市的生命元
		return element;
	}
	void element_reduce(int e) {
		element -= e;
		return;
	}
	warrior* c_w(int i) {//city ci的第i个武士
		return p[i];
	}
	void set_p(int i,warrior*w) {
		p[i] = w;
		return;
	}

}c[30];//第0个城市为红方司令部 第N+1个城市为蓝方司令部
city tmp[30];
inline warrior* city_warrior(int i, int j) {
	return c[i].p[j];
}
class warrior {//武士类 其他具体的武士都由这个派生而来
public://我太难受了 一开始搞了好多private 啥啥都不方便 写不动了 改成public吧
	int id;//武士的编号
	int color;//红方或蓝方
	int type;//是哪一种武士
	int place;//现左他在哪个城市
public:
	int loyalty;
	weapon w[3][10];//武士的武器
	int weapon_num;//武器总数
	int force;//攻击力
	int element;//生命值
	virtual void born(int ty,int co) {
		type = ty;
		element = ele[type];
		force = ATK[type];
		color = co;
		place = co;
		weapon_num = 0;
		id = ID[color];
		for (int i = 0; i < 3; ++i) {//初始化武器 全部设为没有
			for (int j = 0; j < 10; ++j) {
				w[i][j].ATK = -1;
				w[i][j].used = 0;
			}
		}
		if (color == red) {
			c[red].p[0] = this;
		}
		if (color == blue) {
			c[blue].p[1] = this;
		}
		print_time();
		cout << its_color_name() << " "<<its_type()<<" " << its_id() << " born" << endl;
	}
	int its_element() {
		return element;
	}
	void element_reduce(int e) {
		element -= e;
	}
	virtual void run() {
		return;
	}
	string its_type() {
		return name[type];
	}
	string its_color_name() {
		return color_name[color];
	}
	int its_color() {
		return color;
	}
	int its_id() {
		return id;
	}
	int its_place() {
		return place;
	}
	virtual void march() {
		if (color == red)
			place++;
		if (color == blue)
			place--;

		//print_time();
		//cout << its_color_name() << " " << its_type() << " " << its_id() << " marched to city " << place << endl;
	}
	void get_weapon(int w_type) {
		if (w_type == Sword) {
			sword s(force / 5);
			w[Sword][0] = s;
		}
		if (w_type == Bomb) {
			bomb b(force * 2 / 5);
			w[Bomb][0] = b;
		}
		if (w_type == Arrow) {
			arrow a(force * 3 / 10);
			w[Arrow][0] = a;
			
		}
		weapon_num++;
	}
	virtual void rob() {
		return;
	}
	virtual void cheer() {
		return;
	}
};

void weapon::attack(warrior* w1, warrior* w2) {//使用者w1 受害者w2
	w2->element -= ATK;
}
void bomb::attack(warrior* w1, warrior* w2) {
	weapon::attack(w1, w2);
	if (w1->type != Ninja)//ninja 使用bomb不会让自己受伤
		w1->element -= ATK / 2;
	ATK = -1;//bomb一旦使用就没了

}
void arrow::attack(warrior* w1, warrior* w2) {
	weapon::attack(w1, w2);
	used++;//一个arrow只能用两次
	if (used >= 2) {
		ATK = -1;
	}
}
class dragon :public warrior {//dragon从warrior继承
public:
	void cheer() {
		print_time();
		cout << color_name[its_color()] << " dragon " << its_id() << " yelled in city " << its_place() << endl;
	}
	void born(int ty,int co) {
		warrior::born(ty,co);
		int w_type = ID[its_color()] % 3;
		get_weapon(w_type);
		
	}
};
class ninja :public warrior {
	void born(int ty,int co) {
		warrior::born(ty,co);
		int w1 = (ID[its_color()]) % 3;
		int w2 = (ID[its_color()] + 1) % 3;
		get_weapon(w1);
		get_weapon(w2);
	}
};

class iceman :public warrior {
public:
	void march() {
		warrior::march();
		element_reduce(its_element() / 10);
		//iceman每前进一步，生命值减少10%(减少的量要去尾取整)
	}
	void born(int ty, int co) {
		warrior::born(ty, co);
		int w_type = (ID[its_color()]) % 3;
		get_weapon(w_type);
	}
};
class lion :public warrior {
private:
	void run() {
		//忠诚度降至0或0以下，则该lion逃离战场,永远消失。
		if (loyalty <= 0) {
			if (color == red) {
				c[place].p[0] = NULL;
			}
			if (color == blue) {
				c[place].p[1] = NULL;
			}
			print_time();
			cout << its_color_name() << " lion " << its_id() << " ran away" << endl;
			delete this;
		}
	}
	void born(int ty,int co) {
		warrior::born(ty,co);
		int w_type = ID[its_color()] % 3;
		get_weapon(w_type);
		loyalty = c[its_color()].its_element();//其初始值等于它降生之后其司令部剩余生命元的数目。
		cout << "Its loyalty is " << loyalty << endl;
	}
	void march() {
		warrior::march();
		loyalty -= K;//每前进一步就下降K
	}
};
class wolf :public warrior {
	void rob() {
		//抢敌人的武器 w1抢w2

		int ii = its_place();//事情发生的地点
		//抢武器
		warrior* w1;
		warrior* w2;
		if (its_color() == red) {
			w1 = c[ii].c_w(0);
			w2 = c[ii].c_w(1);
		}
		else {
			w1 = c[ii].c_w(1);
			w2 = c[ii].c_w(0);
		}
		if (!w1 || !w2) {
			return;
		}
		if (w1->type == Wolf && w2->type == Wolf)//都是狼就不抢
			return;
		int num = 0;
		bool has_rob = false;
		for (int i = 0; i < 2; ++i) {
			num = 0;
			if (has_rob) {
				cout << "from " << color_type_id(w2) << " in city " << ii << endl;
				return;
			}
			for (int j = 0; j < 10; ++j) {
				if (w1->weapon_num >= 10) {
					if (has_rob) {
						cout << "from " << color_type_id(w2) << " in city " << ii << endl;
					}
					return;
				}
				if (w2->w[i][j].ATK >= 0) {
					if (!has_rob) {
						has_rob = true;
						print_time();
						cout << color_type_id(w1) << " took ";
					}
					gain_weapon(w1, i,0);
					w2->w[i][j].ATK = -1;
					(w2->weapon_num)--;
					num++;
				}
			}
			if (num) {
				cout << num << " " << weapon_name[i] << " ";
			}
		}
		if (has_rob) {
			cout << "from " << color_type_id(w2) << " in city " << ii << endl;
			return;
		}
		num = 0;
		for (int j = 0; j < 10; ++j) {///抢没用过的Arrow
			if (w1->weapon_num >= 10) {
				if (has_rob) {
					cout << "from " << color_type_id(w2) << " in city " << ii << endl;
				}
				return;
			}
			if (w2->w[Arrow][j].ATK >= 0&& w2->w[Arrow][j].used==0) {
				if (!has_rob) {
					has_rob = true;
					print_time();
					cout << color_type_id(w1) << " took ";
				}
				gain_weapon(w1, Arrow, 0);
				w2->w[Arrow][j].ATK = -1;
				(w2->weapon_num)--;
				num++;
			}
		}
		for (int j = 0; j < 10; ++j) {//抢用过的Arrow
			if (w1->weapon_num >= 10) {
				if (has_rob) {
					cout << "from " << color_type_id(w2) << " in city " << ii << endl;
				}
				return;
			}
			if (w2->w[Arrow][j].ATK >= 0 && w2->w[Arrow][j].used == 1) {
				if (!has_rob) {
					has_rob = true;
					print_time();
					cout << color_type_id(w1) << " took ";
				}
				gain_weapon(w1, Arrow, 1);
				w2->w[Arrow][j].ATK = -1;
				(w2->weapon_num)--;
				num++;
			}
		}
		if (num) {
			cout << num << " " << weapon_name[Arrow] << " ";
		}

		if (has_rob) {
			cout << "from " << color_type_id(w2) << " in city " << ii << endl;
		}
		return;
	}
};

void warrior_born(int color) {
	int type = 0;
	if (color == red) {
		type = (ID[red] -1)% 5;
	}
	if (color == blue)
	{
		switch ((ID[blue] - 1) % 5) {
		case 0:type = Lion; break;
		case 1:type = Dragon; break;
		case 2:type = Ninja; break;
		case 3:type = Iceman; break;
		case 4:type = Wolf; break;
		default:cout << "born error" << endl;
		}
	}
	if (c[color].its_element() < ele[type]) {
		return;//生命元不够 造不了
	}
	else {
		c[color].element_reduce(ele[type]);//司令部生命元减少
		
	}
	warrior* w = NULL;
	if (type == Iceman) {
		w = new iceman;
	}
	if (type == Lion) {
		w = new lion;
	}
	if (type == Wolf) {
		w = new wolf;
	}
	if (type == Ninja) {
		w = new ninja;
	}
	if (type == Dragon) {
		w = new dragon;
	}
	
	w->born(type,color);
	ID[color]++;
}
void gain_weapon(warrior* w1, int wtype,int used) {
	(w1->weapon_num)++;
	for (int j = 0; j < 10; ++j) {
		if (w1->w[wtype][j].ATK < 0) {
			switch (wtype) {
			case Sword:w1->w[wtype][j].ATK = w1->force / 5; return;
			case Bomb:w1->w[wtype][j].ATK = w1->force * 2 / 5; return;
			case Arrow:w1->w[wtype][j].ATK = w1->force * 3 / 10; w1->w[wtype][j].used = used; return;
			}
		}
	}
}
void rob_weapon(warrior* w1, warrior* w2) {//w1抢w2的武器
	for (int i = Sword; i <= Bomb; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (w1->weapon_num >= 10)
				return;
			if (w2->w[i][j].ATK >= 0) {//敌人有这种武器
				gain_weapon(w1, i, 0);
				w2->w[i][j].ATK = -1;
				(w2->weapon_num)--;
			}
		}
	}
	for (int j = 0; j < 10; ++j) {
		if (w1->weapon_num >= 10) {
			return;
		}
		if (w2->w[Arrow][j].ATK >= 0&& w2->w[Arrow][j].used==0) {
			gain_weapon(w1, Arrow, 0);//先抢没用过的
			w2->w[Arrow][j].ATK = -1;
			(w2->weapon_num)--;
		}
	}
	for (int j = 0; j < 10; ++j) {
		if (w1->weapon_num >= 10) {
			return;
		}
		if (w2->w[Arrow][j].ATK >= 0&& w2->w[Arrow][j].used==1) {
			gain_weapon(w1, Arrow, 1);
			w2->w[Arrow][j].ATK = -1;
			(w2->weapon_num)--;
		}
	}
}
void fight(int i) {//在i号城发生战斗
	if (!(c[i].c_w(0) && c[i].c_w(1)))//少于两个人 打不起来
		return;
	warrior* redw=NULL;
	warrior* bluew=NULL;
	if (i % 2) {//奇数号城市红武士先攻击
		int ri = 0;//用第几件武器
		int rj = 0;//的第几个
		int bi = 0;
		int bj = 0;
		redw = c[i].c_w(0);
		bluew = c[i].c_w(1);
		int cnt = 0;
		while (redw->element > 0 && bluew->element > 0) {//都活着
			cnt++;
			if (cnt > 200)
				break;//生命值都不再变化
			if (redw->weapon_num <= 0 && bluew->weapon_num <= 0)
				break;
			//红方攻击
			bool has_attack = false;
			for (; redw->weapon_num>0; ri = (ri + 1) % 3,rj=0) {
				if (has_attack)
					break;
				if (ri == Arrow) {//就要先用用过的
					for (int j = 0; j < 10; ++j) {
						if (has_attack)
							break;
						if (redw->w[ri][j].ATK >= 0 && redw->w[ri][j].used == 1) {
							redw->w[ri][j].attack(redw, bluew);
							has_attack = true;
							redw->weapon_num--;
							redw->w[ri][j].ATK = -1;//这箭不能用了
							redw->w[ri][j].used = 0;
							if (bluew->element <= 0) {
								//蓝的死了
								print_time();
								rob_weapon(redw, bluew);
								cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
								c[i].set_p(1, NULL);
								delete bluew;
								redw->cheer();
								return;
							}
						}
						if (has_attack)
							break;
					}
					if (has_attack) {
						break;
					}
					for (int j = 0; j < 10; ++j) {
						if (has_attack)
							break;
						if (redw->w[ri][j].ATK >= 0 && redw->w[ri][j].used == 0) {//用没用过的Arrow
							redw->w[ri][j].attack(redw, bluew);
							has_attack = true;
							redw->w[ri][j].used++;
							
							if (bluew->element <= 0) {
								//蓝的死了
								print_time();
								rob_weapon(redw, bluew);
								cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
								c[i].set_p(1, NULL);
								delete bluew;
								redw->cheer();
								return;
							}
						}
					}
				}
				else {//如果不是Arrow
					
					for (; rj < 10; rj = (rj + 1)) {
						if (has_attack)
							break;
						if (redw->w[ri][rj].ATK >= 0) {//表示有这个武器
							redw->w[ri][rj].attack(redw, bluew);//攻击
							has_attack = true;
							if (ri == Bomb) {
								
								if (redw->type != Ninja) {
									redw->element -= redw->w[ri][rj].ATK / 2;
								}
								redw->weapon_num--;
								redw->w[ri][rj].ATK = -1;
								if (redw->element <= 0&&bluew->element>0) {
									//把自己炸死了
									rob_weapon(bluew, redw);
									print_time();
									cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
									c[i].set_p(0, NULL);
									delete redw;
									bluew->cheer();
									return;
								}
								
							}
							if (bluew->element <= 0&&redw->element<=0) {
								//都死了
								print_time();
								cout << "both " << color_type_id(redw) << " and " << color_type_id(bluew) << " died in city " << i << endl;
								c[i].set_p(1, NULL);
								c[i].set_p(0, NULL);
								delete bluew;
								delete redw;
								return;
							}

							if (bluew->element <= 0) {
								//蓝的死了
								rob_weapon(redw, bluew);
								print_time();
								cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
								c[i].set_p(1, NULL);
								delete bluew;
								redw->cheer();
								return;
							}

						}
					}
				}
				if (has_attack) {
					break;
				}
			}
			

			//蓝的攻击
			has_attack = false;
			for (; bluew->weapon_num > 0; bi = (bi + 1) % 3,bj=0) {
				if (has_attack)
					break;
				if (bi == Arrow) {//就要先用用过的
					for (int j = 0; j < 10; ++j) {
						if (has_attack)
							break;
						if (bluew->w[bi][j].ATK >= 0 && bluew->w[bi][j].used == 1) {
							bluew->w[bi][j].attack(bluew, redw);
							has_attack = true;
							bluew->weapon_num--;
							bluew->w[bi][j].ATK = -1;//这箭不能用了
							bluew->w[bi][j].used = 0;
							if (redw->element <= 0) {
								//红的死了
								rob_weapon(bluew, redw);
								print_time();
								cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
								c[i].set_p(0, NULL);
								delete redw;
								bluew->cheer();
								return;
							}
						}
						if (has_attack)
							break;
					}
					if (has_attack)
						break;
					for (int j = 0; j < 10; ++j) {//再用没用过的
						if (has_attack)
							break;
						if (bluew->w[bi][j].ATK >= 0 && bluew->w[bi][j].used == 0) {
							bluew->w[bi][j].attack(bluew, redw);
							has_attack = true;
							bluew->w[bi][j].used++;
							
							if (redw->element <= 0) {
								//红的死了
								rob_weapon(bluew, redw);
								print_time();
								cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
								c[i].set_p(0, NULL);
								delete redw;
								bluew->cheer();
								return;
							}
						}
					}
				}
				else {
					
					for (; bj < 10; bj = (bj + 1)) {
						if (has_attack)
							break;
						if (bluew->w[bi][bj].ATK >= 0) {//表示有这个武器
							bluew->w[bi][bj].attack(bluew, redw);//攻击
							has_attack = true;
							if (bi == Bomb) {
								
								if (bluew->type != Ninja) {
									bluew->element -= bluew->w[bi][bj].ATK / 2;
								}
								bluew->weapon_num--;
								bluew->w[bi][bj].ATK = -1;
								if (bluew->element <= 0&&redw->element>0) {
									//把自己炸死了
									rob_weapon(redw, bluew);
									print_time();
									cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
									c[i].set_p(1, NULL);
									delete bluew;
									redw->cheer();
									return;
								}
								
							}
							if (bluew->element <= 0 && redw->element <= 0) {
								//都死了
								print_time();
								cout << "both " << color_type_id(redw) << " and " << color_type_id(bluew) << " died in city " << i << endl;
								c[i].set_p(1, NULL);
								c[i].set_p(0, NULL);
								delete bluew;
								delete redw;
								return;
							}

							if (redw->element <= 0) {
								//红的死了
								rob_weapon(bluew, redw);
								print_time();
								cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
								c[i].set_p(0, NULL);
								delete redw;
								bluew->cheer();
								return;
							}

						}
					}
				}
				if (has_attack) {
					break;
				}
			}
		}
	}



	if (i % 2==0) {//偶数号城市蓝武士先攻击
		int ri = 0;//用第几件武器
		int rj = 0;//的第几个
		int bi = 0;
		int bj = 0;
		redw = c[i].c_w(0);
		bluew = c[i].c_w(1);
		int cnt = 0;
		while (redw->element > 0 && bluew->element > 0) {//都活着
			cnt++;
			if (cnt > 200)
				break;
			//蓝的攻击
			if (bluew->weapon_num <= 0 && redw->weapon_num <= 0)
				break;
			bool has_attack = false;
			for (; bluew->weapon_num > 0; bi = (bi + 1) % 3,bj=0) {
				if (bi == Arrow) {//就要先用用过的
					for (int j = 0; j < 10; ++j) {
						if (has_attack)
							break;
						if (bluew->w[bi][j].ATK >= 0 && bluew->w[bi][j].used == 1) {
							bluew->w[bi][j].attack(bluew, redw);
							has_attack = true;
							bluew->weapon_num--;
							bluew->w[bi][j].ATK = -1;//这箭不能用了
							bluew->w[bi][j].used = 0;
							if (redw->element <= 0) {
								//红的死了
								rob_weapon(bluew, redw);
								print_time();
								cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
								c[i].set_p(0, NULL);
								delete redw;
								bluew->cheer();
								return;
							}
						}
						if (has_attack)
							break;
					}
					if (has_attack)
						break;
					for (int j = 0; j < 10; ++j) {//再用没用过的
						if (has_attack)
							break;
						if (bluew->w[bi][j].ATK < 0 || bluew->w[bi][j].used != 0)
							continue;
						bluew->w[bi][j].attack(bluew, redw);
						has_attack = true;
						bluew->w[bi][j].used++;

						if (redw->element <= 0) {
							//红的死了
							rob_weapon(bluew, redw);
							print_time();
							cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
							c[i].set_p(0, NULL);
							delete redw;
							bluew->cheer();
							return;
						}
					}
				}
				else {
					for (; bj < 10; bj = (bj + 1)) {
						if (has_attack)
							break;
						if (bluew->w[bi][bj].ATK >= 0) {//表示有这个武器
							bluew->w[bi][bj].attack(bluew, redw);//攻击
							has_attack = true;
							if (bi == Bomb) {
								
								if (bluew->type != Ninja) {
									bluew->element -= bluew->w[bi][bj].ATK / 2;
								}
								bluew->weapon_num--;
								bluew->w[bi][bj].ATK = -1;
								if (bluew->element <= 0&&redw->element>0) {
									//把自己炸死了
									rob_weapon(redw, bluew);
									print_time();
									cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
									c[i].set_p(1, NULL);
									delete bluew;
									redw->cheer();
									return;
								}
								
							}
							if (bluew->element <= 0 && redw->element <= 0) {
								//都死了
								print_time();
								cout << "both " << color_type_id(redw) << " and " << color_type_id(bluew) << " died in city " << i << endl;
								c[i].set_p(1, NULL);
								c[i].set_p(0, NULL);
								delete bluew;
								delete redw;
								return;
							}

							if (redw->element <= 0) {
								//红的死了
								rob_weapon(bluew, redw);
								print_time();
								cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
								c[i].set_p(0, NULL);
								delete redw;
								bluew->cheer();
								return;
							}

						}
					}
				}
				if (has_attack) {
					break;
				}
			}

			//红方攻击
			has_attack = false;
			for (; redw->weapon_num > 0; ri = (ri + 1) % 3,rj=0) {
				if (has_attack)
					break;
				if (ri == Arrow) {//就要先用用过的
					for (int j = 0; j < 10; ++j) {
						if (has_attack)
							break;
						if (redw->w[ri][j].ATK >= 0 && redw->w[ri][j].used == 1) {
							redw->w[ri][j].attack(redw, bluew);
							has_attack = true;
							redw->weapon_num--;
							redw->w[ri][j].ATK = -1;//这箭不能用了
							redw->w[ri][j].used = 0;
							if (bluew->element <= 0) {
								//蓝的死了
								rob_weapon(redw, bluew);
								print_time();
								cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
								c[i].set_p(1, NULL);
								delete bluew;
								redw->cheer();
								return;
							}
						}
						if (has_attack)
							break;
						
					}
					if (has_attack)
						break;
					for (int j = 0; j < 10; ++j) {
						if (has_attack)
							break;
						if (redw->w[ri][j].ATK < 0 || redw->w[ri][j].used != 0)
							continue;
						redw->w[ri][j].attack(redw, bluew);
						has_attack = true;
						redw->w[ri][j].used++;

						if (bluew->element <= 0) {
							//蓝的死了
							rob_weapon(redw, bluew);
							print_time();
							cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
							c[i].set_p(1, NULL);
							delete bluew;
							redw->cheer();
							return;
						}
					}
				}
				else {
					for (; rj < 10; rj = (rj + 1)) {
						if (has_attack)
							break;
						if (redw->w[ri][rj].ATK >= 0) {//表示有这个武器
							redw->w[ri][rj].attack(redw, bluew);//攻击
							has_attack = true;
							if (ri == Bomb) {
								
								if (redw->type != Ninja) {
									redw->element -= redw->w[ri][rj].ATK / 2;
								}
								redw->weapon_num--;
								redw->w[ri][rj].ATK = -1;
								if (redw->element <= 0&&bluew->element>0) {
									//把自己炸死了
									rob_weapon(bluew, redw);
									print_time();
									cout << color_type_id(bluew) << " killed " << color_type_id(redw) << " in city " << i << " remaining " << bluew->element << " elements" << endl;
									c[i].set_p(0, NULL);
									delete redw;
									bluew->cheer();
									return;
								}
								
							}
							if (bluew->element <= 0 && redw->element <= 0) {
								//都死了
								print_time();
								cout << "both " << color_type_id(redw) << " and " << color_type_id(bluew) << " died in city " << i << endl;
								c[i].set_p(1, NULL);
								c[i].set_p(0, NULL);
								delete bluew;
								delete redw;
								return;
							}

							if (bluew->element <= 0) {
								//蓝的死了
								rob_weapon(redw, bluew);
								print_time();
								cout << color_type_id(redw) << " killed " << color_type_id(bluew) << " in city " << i << " remaining " << redw->element << " elements" << endl;
								c[i].set_p(1, NULL);
								delete bluew;
								redw->cheer();
								return;
							}

						}
					}
				}
				if (has_attack) {
					break;
				}
			}

		}
	}
	
	print_time();
	cout << "both " << color_type_id(redw) << " and " << color_type_id(bluew) << " were alive in city " << i << endl;
	redw->cheer();
	bluew->cheer();
}
string color_type_id(warrior* w) {
	//char str[10];
	//itoa(w->its_id(), str, 10);
	string str;
	stringstream ss;
	ss << w->its_id();
	str= ss.str();
	return color_name[w->its_color()] + " " + w->its_type() + " " + str+"\0";
}
bool check_arrive(int ci) {
	warrior* w1 = c[0].c_w(1);
	warrior* w2 = c[N+1].c_w(0);
	if (w1&&w1->its_color() == blue&&ci==0) {
		print_time();
		cout <<color_type_id(w1)<< " reached red headquarter with " << w1->element << " elements and force " << w1->force << endl;
		print_time();
		cout << "red headquarter was taken" << endl;
		return true;
	
	}
	if (w2 && w2->its_color() == red&&ci==N+1) {
		print_time();
		cout << color_type_id(w2)<< " reached blue headquarter with " << w2->element << " elements and force " << w2->force << endl;
		print_time();
		cout << "blue headquarter was taken" << endl;
		return true;
	}
	return false;
}

void announce() {
	print_time();
	cout << c[red].its_element() << " elements in red headquarter" << endl;
	print_time();
	cout << c[blue].its_element() << " elements in blue headquarter" << endl;

}
void warrior_announce() {
	for (int i = red; i <= blue; ++i) {
		for (int j = 0; j < 2; ++j) {
			warrior* ww = c[i].c_w(j);
			if (ww) {
				print_time();
				cout << ww->its_color_name() << " " << ww->its_type() << " " << ww->its_id()<<" has ";
				for (int i = 0; i < 3; ++i) {
					int num = 0;
					for (int j = 0; j < 10; ++j) {
						if (ww->w[i][j].ATK >= 0) {
							num++;
						}
					}
					cout << num << " " << weapon_name[i] << " ";
				}
				cout << "and " << ww->element << " elements" << endl;
			}
		}
	}
}
inline void input() {//输入和一些初始化
	cin >> M >> N >> K >> T;
	color_name[red] = "red";
	color_name[blue] = "blue";
	ID[red] = 1;
	ID[blue] = 1;
	Time = 0;
	c[red].element = M;
	c[blue].element = M;
	cin >> ele[Dragon] >> ele[Ninja] >> ele[Iceman] >> ele[Lion] >> ele[Wolf];
	cin >> ATK[Dragon] >> ATK[Ninja] >> ATK[Iceman] >> ATK[Lion] >> ATK[Wolf];
	for (int i = red; i <= blue; ++i) {
		for (int j = 0; j < 2; ++j) {
			c[i].p[j] = NULL;//城市初始化
			tmp[i].p[j] = NULL;
		}
	}
	return;
}
int main() {
	
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case " << i << ":" << endl;
		input();
		
		while (Time <= T) {
			//0分 武士降生
			warrior_born(red);
			warrior_born(blue);
			//5分 lion 逃跑
			Time += 5;
			if (Time > T)
				break;
			for (int i = 0; i <= N + 1; ++i) {
				for (int j = 0; j < 2; ++j) {
					warrior* w = city_warrior(i, j);
					if (w)
						w->run();
				}
			}
			//10分 武士前进 ( 武士抵达司令部 司令部被占领
			Time += 5;
			if (Time > T)
				break;
			memset(tmp, 0, sizeof(tmp));
			for (int i = 0; i <= N + 1; ++i) {
				for (int j = 0; j < 2; ++j) {
					warrior* w = city_warrior(i, j);
					if (w) {
						w->march();
						tmp[w->its_place()].set_p(j, w);
					}
				}
			}
			bool f = false;

			for (int i = 0; i <= N + 1; ++i) {
				for (int j = 0; j < 2; ++j) {
					warrior* tmpw = tmp[i].c_w(j);
					c[i].set_p(j, tmpw);//拷贝过来
					if (tmpw == NULL)
						continue;

					if (i == red || i == blue) {
						f = check_arrive(i);
					}
					if (i == red || i == blue)
						continue;
					print_time();
					cout << color_type_id(tmpw) << " marched to city " << i << " with " << tmpw->element << " elements and force " << tmpw->force << endl;
				}
			}
			if (f)
				break;
			//35分 wolf抢武器
			Time += 25;
			if (Time > T)
				break;
			for (int i = 0; i <= N + 1; ++i) {
				for (int j = 0; j < 2; ++j) {
					warrior* w = city_warrior(i, j);
					if (w) {
						w->rob();
					}
				}
			}

			//40分 报告战斗情况 武士欢呼
			Time += 5;
			if (Time > T)
				break;
			for (int i = red; i <= blue; ++i) {
				fight(i);
			}


			//50分 司令部报告生命元数量
			Time += 10;
			if (Time > T)
				break;
			announce();

			//55分 武士报告情况
			Time += 5;
			if (Time > T)
				break;
			warrior_announce();
			Time += 5;
		}
	}
}
