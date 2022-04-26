/*����
����n��������������������д�С����ǰk��ż��



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
// �ڴ˴�������Ĵ���
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
����
�ж�������
��һ������������ t
��ÿ�����ݣ�
��һ��Ϊ����n (n>=3)��k
��������һ��Ϊn����������֤��Щ������������k��ż����
���
��ÿ�����ݣ����k���������������У���ʾѡ�����Ĵ�С����ǰk��ż��
��������
2
9 4
1 2 4 3 6 6 7 8 9
3 2
18 16 14
�������
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
	// �ڴ˴�������Ĵ���
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
