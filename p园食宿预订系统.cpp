/*����
ĳУ԰Ϊ����ѧ�����ͣ��Ƴ�ʳ��Ԥ��ϵͳ��ʳ��ƽ̨����ǰһ���ṩ�˵���ѧ���ڿ���ʱ��ǰ�ɶ��͡� ʳ��ÿ����Ƴ�m���ˣ�ÿ�����й̶��Ĳ˼ۺ��ܷ����������������ܳ����ܷ����� ���蹲��n��ѧ����ͣ�ÿ��ѧ���̶���3���ˣ�����Ĳ�����ʱ, ѧ�����򲻵�������ˡ� �����ѧ��Ԥ����¼������ʳ���ܵ�Ԥ������ ��������1 <= n <= 6000��3 <= m <= 6000����Ʒ�˼۲�����1000Ԫ��ÿ���˵�������3000

����
��һ����������n��m��������n��ѧ�����ͣ�����m����ѡ�Ĳ�
����m�У�ÿ������Ԫ�أ��ֱ��ǲ������ۼۺͿ��ṩ������֤�������غϣ��˼�Ϊ����
����n�У�ÿ������Ԫ�أ���ʾ���ѧ����������˵Ĳ���
���
һ����������ʾʳ�õ�����
��������
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
�������
1157*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
struct meal {
	int price;//�۸�
	int cnt;//�ݶ�
	meal(int p,int c):price(p),cnt(c){ }
	meal() {
		price = 0;
		cnt = 0;
	}
};
int main() {
	int n = 0, m = 0;//n��ѧ�� m����
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
