/*����
����һϵ��������, �������ǵ�ƽ��ֵ�����ȥβȡ����

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
// �ڴ˴�������Ĵ���
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while ( t -- ) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	return 0;
}
����
��һ���ǲ�����������T
����T�У�ÿ��һ�����ݡ�ÿ�������ɸ�����������0��ʾ�������(0����)��
���
��ÿ�����ݣ������������ƽ��ֵ�����ȥβȡ����
��������
1
17 4 8 18 0
�������
11*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
	// �ڴ˴�������Ĵ���
	int n;
	double aver_;
	int* aver;
public:
	CMean(int& a) {
		aver = &a;
		aver_ = a;
		n = 0;
	}
	void operator ()(int i) {
		aver_ = ((aver_ * n) + i) / (n + 1);
		n++;
		*aver = aver_;
	}
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while (t--) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	return 0;
}
