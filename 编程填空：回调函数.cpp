/*����
����x1 x2 x3 x4 x5 �����y = x5^5 + x4^4 + x3^3 + x2^2 + x1^1 + 1��y��ֵ

#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;
class MyFunc
{
// �ڴ˴�������Ĵ���
};
int main()
{
	int n;
	cin >> n;
	while(n--) {
		vector<MyFunc> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(MyFunc(i+1));
		int ans = 1;
		for (int i = 0; i < 5; ++i)
		{
			int m;
			cin >> m;
			ans += v[i](m);
		}
		cout << ans <<endl;
	}
}
����
�������ݡ���һ������������ n
ÿ������Ϊһ��,5��������x1 x2 x3 x4 x5����ֵ���󣬲��ؿ������
���
��ÿ�����ݣ����һ������y�� y = x5^5 + x4^4 + x3^3 + x2^2 + x1^1 + 1
��������
2
2 2 2 2 2
1 1 1 1 1
�������
63
6*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;
class MyFunc
{
// �ڴ˴�������Ĵ���
	int e;
public:
	MyFunc(int i):e(i){	}
	int operator()(int i){
		return pow(i,e);
	}
};
int main()
{
	int n;
	cin >> n;
	while(n--) {
		vector<MyFunc> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(MyFunc(i+1));
		int ans = 1;
		for (int i = 0; i < 5; ++i)
		{
			int m;
			cin >> m;
			ans += v[i](m);
		}
		cout << ans <<endl;
	}
}
