/*����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�
��˾���City 1��City 2��������City n����˾�

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ�����������������ԡ�

˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ�n����ʿ����ž���n��ͬ����������������ĵ�n����ʿ�����Ҳ��n��

��ʿ�ڸս�����ʱ����һ������ֵ��

��ÿ�����㣬˫����˾��и���һ����ʿ������

�췽˾�����iceman��lion��wolf��ninja��dragon��˳��ѭ��������ʿ��

����˾�����lion��dragon��ninja��iceman��wolf��˳��ѭ��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪm����ʿ��˾��е�����Ԫ��Ҫ����m����

���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��

����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������
һ���������¼������Ӧ������������£�

1) ��ʿ����
��������� 004 blue lion 5 born with strength 5,2 lion in red headquarter
��ʾ��4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5����������ħ˾��ﹲ��2��lion��ʿ����Ϊ������������ǵ��ʵĸ�����ʽ��ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��

2) ˾�ֹͣ������ʿ
��������� 010 red headquarter stops making warriors
��ʾ��10�������췽˾�ֹͣ������ʿ

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

����
��һ����һ�������������������������

ÿ��������ݹ����С�

��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)��

�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000��
���
��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���
��ÿ��������ݣ��������"Case:n" n�ǲ������ݵı�ţ���1��ʼ ��
��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��
��������
1
20
3 4 5 6 7
�������
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

int case_num;//������������
int red_energy = 0;//��ʼ����Ԫ
int blue_energy;
int red_num = 0;//���
int blue_num;

vector<string>red_warrior = { "iceman","lion","wolf","ninja","dragon" };
vector<string>blue_warrior = { "lion","dragon","ninja","iceman","wolf" };

struct warrior {
	int HP;//health point ����ֵ
	int ATK;//attack������
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
	
		int type =make_red%5;
			if (red_energy >= red_HP[type]) {
				red_energy -= red_HP[type];//������ѩ��
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

			blue[type].push_back(temp);
			cout <<"blue "<< blue_warrior[type] <<" "<< blue_num << " born with strength " << blue_HP[type];
			cout << "," << blue[type].size() <<" "<< blue_warrior[type] << " in blue headquarter" << endl;
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
