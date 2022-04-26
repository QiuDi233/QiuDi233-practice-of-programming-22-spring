/*描述
输入n个整数，输出整数数列中大小排名前k的偶数



#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
// 在此处补充你的代码
};
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout<<q;
		cout << endl;
	}
	return 0;
}
输入
有多组数据
第一行是数据组数 t
对每组数据：
第一行为整数n (n>=3)和k
接下来的一行为n个整数，保证这些整数中至少有k个偶数。
输出
对每组数据，输出k个整数，降序排列，表示选出来的大小排名前k的偶数
样例输入
2
9 4
1 2 4 3 6 6 7 8 9
3 2
18 16 14
样例输出
8 6 6 4
18 16*/


#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
	// 在此处补充你的代码
	int k;
	priority_queue<int,vector<int>, greater<int>>q;
public:
	MyQueue(int k_):k(k_){ }
	friend istream& operator >>(istream& is, MyQueue &Q) {
		int n;
		is >> n;
		if (n % 2) {
			return is;
		}
		if (Q.q.size()<Q.k) {
			Q.q.push(n);
			return is;
		}
		if (n > Q.q.top()) {
			Q.q.pop();
			Q.q.push(n);
		}
		return is;
	}
	friend ostream& operator <<(ostream& os, MyQueue Q) {
		stack<int>s;
		while (!Q.q.empty()) {
			//os << Q.q.top() << " ";
			s.push(Q.q.top());
			Q.q.pop();
		}
		while (!s.empty()) {
			os << s.top() << " ";
			s.pop();
		}
		return os;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout << q;
		cout << endl;
	}
	return 0;
}
