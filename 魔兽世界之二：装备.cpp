/*����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�

��˾���City 1��City 2��������City n����˾�

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ���������ԡ�
�е���ʿ����ӵ�����������������֣�sword, bomb,��arrow����ŷֱ�Ϊ0,1,2��
˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ� n ����ʿ����ž���n��ͬ����������������ĵ� n ����ʿ�����Ҳ��n��

��ͬ����ʿ�в�ͬ���ص㡣
dragon ����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n%3 ��������dragon���С�ʿ����������ԣ��Ǹ���������
��ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������
ninja����ӵ���������������Ϊn��ninja����ʱ����ñ��Ϊ n%3 �� (n+1)%3��������
iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n%3 ��������
lion �С��ҳ϶ȡ�������ԣ���ֵ��������������˾�ʣ������Ԫ����Ŀ��
wolfû�ص㡣
��ע�⣬���Ժ����Ŀ���ʿ��ʿ��������ֵ���ҳ϶����������ڼ䶼���ܷ����仯���������ã���ʿ���е���������ʹ�ù�����Ҳ�ᷢ���仯��

��ʿ�ڸս�����ʱ����һ������ֵ��

��ÿ�����㣬˫����˾��и���һ����ʿ������

�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��ѭ��������ʿ��

����˾����� lion��dragon��ninja��iceman��wolf ��˳��ѭ��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪ m ����ʿ��˾��е�����Ԫ��Ҫ���� m ����

���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��
����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������
һ���������¼������Ӧ������������£�

1) ��ʿ����
��������� 004 blue lion 5 born with strength 5,2 lion in red headquarter
��ʾ�� 4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5,��������ħ˾��ﹲ��2��lion��ʿ��(Ϊ������������ǵ��ʵĸ�����ʽ)
ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��
����������dragon����ô��Ҫ���һ�У�����
It has a arrow,and it's morale is 23.34
��ʾ��dragon����ʱ�õ���arrow,��ʿ����23.34��Ϊ�������������arrowǰ��Ĺڴ���a,����an��ʿ����ȷ��С�������2λ���������룩
����������ninja����ô��Ҫ���һ�У�����
It has a bomb and a arrow
��ʾ��ninja����ʱ�õ���bomb��arrow��
����������iceman����ô��Ҫ���һ�У�����
It has a sword
��ʾ��iceman����ʱ�õ���sword��
����������lion����ô��Ҫ���һ�У�����
It's loyalty is 24
��ʾ��lion����ʱ���ҳ϶���24��
2) ˾�ֹͣ������ʿ
��������� 010 red headquarter stops making warriors
��ʾ�� 10�������췽˾�ֹͣ������ʿ

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

����
��һ����һ������,�����������������

ÿ��������ݹ����С�

��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)

�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000
���
��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���
��ÿ��������ݣ����������Case:n" n�ǲ������ݵı�ţ���1��ʼ
��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��
��������
1
20
3 4 5 6 7
�������
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
int case_num;//������������
int red_energy = 0;//��ʼ����Ԫ
int blue_energy;
int red_num = 0;//���
int blue_num;

vector<string>red_warrior = { "iceman","lion","wolf","ninja","dragon" };
vector<string>blue_warrior = { "lion","dragon","ninja","iceman","wolf" };

vector<string>weapon = { "sword","bomb","arrow" };

struct warrior {
	int HP;//health point ����ֵ
	int ATK;//attack������
	double morale;
	int loyalty;
	vector<int>weapon;
};

//��ʼѪ��ֵ


vector<int>red_HP = { 0,0,0,0,0 };
vector<int>blue_HP = { 0,0,0,0,0 };

vector<vector<warrior>>red;//��һάΪ������ʿ �ڶ�άΪÿ����ʿ��ÿһ��
vector<vector<warrior>>blue;//��һάΪ������ʿ �ڶ�άΪÿ����ʿ��ÿһ��

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
	bool f[5];//��������
	if (red_enough) {
		printf("%03d", time);
		cout << " ";
		for (int i = 0; i < 5; i++)
			f[i] = true;
	}


	while (red_enough) {

		int type = make_red % 5;
		if (red_energy >= red_HP[type]) {
			red_energy -= red_HP[type];//������ѩ��
			red_num++;

			warrior temp;
			temp.HP = red_HP[type];
			temp.ATK = 0;
			if (type == red_dragon)
			{
				int w = red_num % 3;//���������
				temp.weapon.push_back(w);
				temp.morale = red_energy / red_HP[red_dragon];//����ʿ��

			}

			if (type == red_iceman)
			{
				int w = red_num % 3;//ѩ�˻������
				temp.weapon.push_back(w);
			}


			if (type == red_ninja)
			{
				int w1 = red_num % 3;//���߻������
				int w2 = (red_num + 1) % 3;
				temp.weapon.push_back(w1);
				temp.weapon.push_back(w2);
			}

			if (type == red_lion) {
				int loy = red_energy;
				temp.loyalty = loy;//ʨ�ӵ��ҳ϶�
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
			f[type] = false;//��������
			if (!f[red_iceman] && !f[red_wolf] && !f[red_lion] && !f[red_dragon] && !f[red_ninja]) {
				//���ȫ������

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
			blue_energy -= blue_HP[type];//������ѩ��
			blue_num++;
			warrior temp;
			temp.HP = blue_HP[type];
			temp.ATK = 0;

			if (type == blue_dragon)
			{
				int w = blue_num % 3;//���������
				temp.weapon.push_back(w);
				temp.morale = blue_energy / blue_HP[blue_dragon];//����ʿ��

			}

			if (type == blue_iceman)
			{
				int w =blue_num % 3;//ѩ�˻������
				temp.weapon.push_back(w);
			}


			if (type == blue_ninja)
			{
				int w1 = blue_num % 3;//���߻������
				int w2 = (blue_num + 1) % 3;
				temp.weapon.push_back(w1);
				temp.weapon.push_back(w2);
			}

			if (type == blue_lion) {
				int loy = blue_energy;
				temp.loyalty = loy;//ʨ�ӵ��ҳ϶�
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
			f[type] = false;//��������
			if (!f[blue_lion] && !f[blue_ninja] && !f[blue_wolf] && !f[blue_dragon] && !f[blue_iceman]) {
				//���ȫ������

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
		int time = 0;//ʱ��
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
