/*����
Ϊ��ӭ��08��İ��˻ᣬ�ô�Ҹ����˽���ָ��˶���facer�¿���һ����Ѫ�񶷳����񶷳�ʵ�л�Ա�ƣ����������Ļ�Ա����Ҫ�����ѣ�
��ֻҪͬһ���ϻ�Ա��һ����������֤���Լ���ʵ����

���Ǽ���񶷵�ʵ��������һ����������ʾ����Ϊʵ��ֵ�����⣬ÿ���˶���һ��Ψһ��id��Ҳ��һ����������
Ϊ��ʹ�ñ������ÿ���ÿһ���¶�Ա����ѡ������ʵ����Ϊ�ӽ����˱�����������˫����ʵ��ֵ֮��ľ���ֵԽСԽ�ã�
����������˵�ʵ��ֵ���������ͬ��������ѡ����������Ǹ�����Ȼ��Ű�˱ر�Ű�ã���

���ҵ��ǣ�Facerһ��С�İѱ�����¼Ū���ˣ��������������Ż�Ա��ע���¼��
���������facer�ָ�������¼������ʱ��˳���������ÿ������˫����id��

����
��һ��һ����n(0 < n <=100000)����ʾ�񶷳������Ļ�Ա����������facer�����Ժ�n��ÿһ������������������ʱ�������Ա��id��ʵ��ֵ��һ��ʼ��facer�����ǻ�Ա��idΪ1��ʵ��ֵ1000000000�����뱣֤���˵�ʵ��ֵ��ͬ��

���
N�У�ÿ����������Ϊÿ������˫����id�����ֵ�idд��ǰ�档

��������
3
2 1
3 3
4 2
�������
2 1
3 2
4 2*/


#include<iostream>
#include<map>
using namespace std;
int main() {
	map<int, int>club;//ʵ�� id
	int n = 0;
	cin >> n;
	int id = 0, force = 0;
	club.insert(pair<int, int>(1000000000,1));
	while (n--) {
		cin >> id >> force;
		club.insert(pair<int,int>(force, id));
		map<int, int>::iterator it, pre, last;
		it = club.find(force);
		pre = last = it;
		pre--;
		last++;
		if (it == club.begin()) {//����
			cout << id << " " << last->second << endl;
		}
		else if (last == club.end()) {//��ǿ
			cout << id << " " << pre->second << endl;
		}
		else {
			if (it->first - pre->first > last->first - it->first) {
				cout << id << " " << last->second<<endl;
			}
			if (it->first - pre->first < last->first -it->first) {
				cout << id << " " << pre->second << endl;
			}
			if (it->first - pre->first == last->first - it->first) {
				cout << id << " " << pre->second << endl;//һ���Ļ��ʹ�˵�
			}
		}
	}
	return 0;
}