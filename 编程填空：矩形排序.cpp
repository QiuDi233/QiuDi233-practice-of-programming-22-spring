/*����
����һϵ�б߳���֪�ľ��Σ�����Ծ��ν�����������Ľ����

�ڵ�һ�������У��Ȱ����ε�����Ӵ�С�������������ε������ͬ�����ܳ��������ǰ��

�ڵڶ��������У��Ȱ����ε��ܳ���С�����������������ε��ܳ���ͬ�������С������ǰ��



#include <iostream>
#include <set>
using namespace std;
// �ڴ˴�������Ĵ���
int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}
����
��һ����һ������n����ʾ����ľ��θ�����
������n�б�ʾ��n�����Ρ�ÿ������������a��b����ʾ�þ��εĳ����
���
����n�������һ������Ľ����ÿ���������������α�ʾ�þ��ε�������ܳ���
�����һ�����С�
�����n������ڶ�������Ľ����ÿ���������������α�ʾ�þ��ε�������ܳ���
��������
6
3 8
4 6
10 2
6 6
4 8
3 6
�������
36 24
32 24
24 22
24 20
20 24
18 18

18 18
24 20
24 22
20 24
32 24
36 24*/

#include <iostream>
#include <set>
using namespace std;
// �ڴ˴�������Ĵ���

class Rectangle{
public:
	int w;
	int h;
	int s;//���
	int c;//�ܳ� 
	friend class Comp;
	Rectangle(int a,int b):w(a),h(b){
		s=a*b;
		c=2*(a+b);
	}
	friend bool operator<(const Rectangle& r1,const Rectangle& r2){
		if(r1.s==r2.s){
			return r1.c>r2.c;
		}
		return r1.s>r2.s;
	}
	friend ostream&operator<<(ostream&os,const Rectangle& r){
		os<<r.s<<" "<<r.c;
		return os;
	}
};
class Comp{
public:
	bool operator()(const Rectangle& r1,const Rectangle& r2)const{
		if(r1.c==r2.c)
			return r1.s<r2.s;
		return r1.c<r2.c;
	}
};
int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}
