/*����
����С����������У�ÿλѵ��ʦ�����ռ��Լ���С���顣���ǣ�ѵ��ʦ�ı�����ֻ��ͬʱЯ��6ֻС���顣���һλѵ��ʦץ���˸���ľ��飬��ô����ץ���ľ��齫���Զ����͵������У���֤���е�С����������Ȼ��6ֻ�� ѵ��ʦҲ������ʱ�ӵ�����ȡ�����飬ȡ���ľ��齫�ӵ����д��͵�ѵ��ʦ�ı����ȡ���ľ���ͬ������Ϊ�����µģ����±���������ȡ����ץ���ľ��鱻�滻�������У�ѵ��ʦ���еľ���������Ȼ��6ֻ�� ��ʼ״̬�£�����ѵ��ʦ�ı����ж�û��С���飬������Ҳû���κ�ѵ��ʦ�ľ��顣

����
�������ݰ���������ԡ���һ��һ������T(1<=T<=20)����ʾ����������Ŀ��
ÿ�����ݵ�һ����һ��������N(1<=N<=20000)��ʾ�����¼�����Ŀ��
��������N�зֱ��ʾ�������¼���
һ���������¼���
C X, Y ��ʾѵ��ʦXץ���˾���Y
T X, Y ��ʾѵ��ʦX��ͼ�ӵ�����ȡ������Y��

X��Y���ǳ�����20���µ�����ĸ�����ֹ��ɵ��ַ�����

С�����������ͬ�������������˵Ļ���ӡ�������ͼ���õ��Ե�©�����ӵ�����ȡ�����������Լ���С���顣��ˣ�������Ҫʶ�𲢾ܾ�ȡ����������ע�⣬���һֻС�����������ѵ��ʦ�ı����ж�δ�����������ԣ���ѵ��ʦҲ����ȡ����ֻ���顣��ͬѵ��ʦ������ץ����ͬ���ֵľ��顣
���
����ÿ�δӵ�����ȡ��С������������һ�С��ɹ������Success��ʧ�������Failed��
��������
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
�������
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
				//ѵ��ʦXץ���˾���Y

				if (backpack.find(X) != backpack.end()) {//ѵ��ʦ�Ѿ���С������
					if (backpack[X].size() == 6) {//������
						pokemon tmp = backpack[X].top();//Ҫ���滻��ȥ��С����
						backpack[X].pop();
						backpack[X].push(pokemon(cnt, Y));
						store[X].push_back(tmp);//�ѱ��滻�ķŵ��ֿ���
					}
					else {//��û����
						backpack[X].push(pokemon(cnt, Y));
					}
				}
				else {
					priority_queue<pokemon, vector<pokemon>, cmp>q;
					q.push(pokemon(1, Y));
					backpack.insert(make_pair(X, q));//Ϊѵ��ʦ��һ������
					list<pokemon>l;//Ϊѵ��ʦ����һ���ֿ�
					store.insert(make_pair(X, l));
				}
			}
			if (ch == 'T') {
				//ѵ��ʦX��ͼ�ӵ�����ȡ������Y
				bool f = false;
				list<pokemon>::iterator it = store[X].begin();
				for (; it != store[X].end(); ++it) {
					if (it->name == Y) {
						//�ŵ�������
						it->n = cnt;//������ֵ ʹ֮��Ϊ����
						if (backpack[X].size() == 6) {//������
							pokemon tmp = backpack[X].top();//Ҫ���滻��ȥ��С����
							backpack[X].pop();
							backpack[X].push(*it);
							store[X].push_back(tmp);//�ѱ��滻�ķŵ��ֿ���
						}
						else {//��û����
							backpack[X].push(*it);
						}
						//�ź���

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
