/*描述
写出 FindFirstLess 模板，用于寻找序列中小于某指定值的第一个元素

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 在此处补充你的代码
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n ;
		string type;
		cin >> n >> type;
		vector<int> vi;
		vector<string> vs;
		if( type == "N") {
			int a,m;
			for(int i = 0;i < n  - 1; ++i) {

				cin >> a;
				vi.push_back(a);
			}
			cin >> m;
			vector<int>::iterator p = FindFirstLess(vi.begin(),vi.end(),m,less<int>());
			if( p!= vi.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl;

		}
		else {
			string a,m;
			for(int i = 0;i < n - 1; ++i) {
				cin >> a;
				vs.push_back(a);
			}
			cin >> m;
			vector<string>::iterator p = FindFirstLess(vs.begin(),vs.end(),m,less<string>());
			if( p!= vs.end())
				cout << * p << endl;
			else
				cout << "Not Found" << endl;

		}
	}
	return 0;
}
输入
第一行是测试数据组数T
接下来有2T行，每两行是一组测试数据
每组数据第一行开始是一个整数，表示这组数据有n项；接下来是一个字母，如果是'N'，表示这组数据都是整数，如果是'S'表示这组数据都是字符串
第二行就是n个整数，或者n个字符串
输出
对每组数据，输出第二行的前n-1项里面，第一个小于第n项的 。如果找不到，输出 "Not Found"
样例输入
3
4 N
28 12 7 15
4 S
Jack Tom Marry Ken
4 N
100 200 300 2
样例输出
12
Jack
Not Found*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 在此处补充你的代码
template<class F>
vector<int>::iterator FindFirstLess(vector<int>::iterator s, vector<int>::iterator e, int m, F f) {
	vector<int>::iterator p = s;
	for (; p != e; p++) {
		if (*p<m )
			return p;
	}
	return p;
}
template<class F>
vector<string>::iterator FindFirstLess(vector<string>::iterator s, vector<string>::iterator e, string m, F f) {
	vector<string>::iterator p = s;
	for (; p != e; p++) {
		if (*p < m)
			return p;
	}
	return p;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		string type;
		cin >> n >> type;
		vector<int> vi;
		vector<string> vs;
		if (type == "N") {
			int a, m;
			for (int i = 0; i < n - 1; ++i) {

				cin >> a;
				vi.push_back(a);
			}
			cin >> m;
			vector<int>::iterator p = FindFirstLess(vi.begin(), vi.end(), m, less<int>());
			if (p != vi.end())
				cout << *p << endl;
			else
				cout << "Not Found" << endl;

		}
		else {
			string a, m;
			for (int i = 0; i < n - 1; ++i) {
				cin >> a;
				vs.push_back(a);
			}
			cin >> m;
			vector<string>::iterator p = FindFirstLess(vs.begin(), vs.end(), m, less<string>());
			if (p != vs.end())
				cout << *p << endl;
			else
				cout << "Not Found" << endl;

		}
	}
	return 0;
}
