/*����
д�� FindFirstLess ģ�壬����Ѱ��������С��ĳָ��ֵ�ĵ�һ��Ԫ��

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// �ڴ˴�������Ĵ���
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
����
��һ���ǲ�����������T
��������2T�У�ÿ������һ���������
ÿ�����ݵ�һ�п�ʼ��һ����������ʾ����������n���������һ����ĸ�������'N'����ʾ�������ݶ��������������'S'��ʾ�������ݶ����ַ���
�ڶ��о���n������������n���ַ���
���
��ÿ�����ݣ�����ڶ��е�ǰn-1�����棬��һ��С�ڵ�n��� ������Ҳ�������� "Not Found"
��������
3
4 N
28 12 7 15
4 S
Jack Tom Marry Ken
4 N
100 200 300 2
�������
12
Jack
Not Found*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// �ڴ˴�������Ĵ���
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
