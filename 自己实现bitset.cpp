/*����
������գ�ʵ��һ������STL bitset�� MyBitset, ���ָ�����
#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset 
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v ) 
			c |= (1 << bp);
		else 
			c &= ~(1 << bp);
	}
// �ڴ˴�������Ĵ���
void Print() {
		for(int i = 0;i < bitNum; ++i) 
			cout << (*this) [i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}
����
��������
ÿ�����ݣ�
��һ�������� n , 1 <= n < 20;
�ڶ�����n������ k1,k2... kn,���ڷ�Χ [0,19]�ڡ�
�������� �ĸ����� i1,j1,k1,v1 �� 0 <= i1,j1,k1 <= 19, v1ֵΪ0��1
�������� �ĸ����� i2,j2,k2,v2 �� 0 <= i2,j2,k2 <= 19, v2ֵΪ0��1
���
��ÿ�����ݣ������3�У�ÿ��20λ��ÿλΪ1����0������߳�Ϊ��0λ
��һ�У� �� k1,k2 ... knλΪ1������λΪ0��
�ڶ��У� ����һ���еĵ� i1,j1,k1λ��Ϊ v1,����λ����
�����У� ���ڶ����еĵ�i2λ��k2λ��Ϊv2������λ����
��������
4
0 1 2 8
7 19 0 1
7 2 8 0
1
1
1 1 1 0
1 1 1 1
�������
11100000100000000000
11100001100000000001
11100000000000000001
01000000000000000000
00000000000000000000
01000000000000000000
��ʾ
�Ƽ�ʹ���ڲ��࣬�ڲ�����ʹ�����ó�Ա�����ó�ԱҪ�ڹ��캯���г�ʼ����*/

/*����
������գ�ʵ��һ������STL bitset�� MyBitset, ���ָ�����
#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v )
			c |= (1 << bp);
		else
			c &= ~(1 << bp);
	}
// �ڴ˴�������Ĵ���
void Print() {
		for(int i = 0;i < bitNum; ++i)
			cout << (*this) [i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}
����
��������
ÿ�����ݣ�
��һ�������� n , 1 <= n < 20;
�ڶ�����n������ k1,k2... kn,���ڷ�Χ [0,19]�ڡ�
�������� �ĸ����� i1,j1,k1,v1 �� 0 <= i1,j1,k1 <= 19, v1ֵΪ0��1
�������� �ĸ����� i2,j2,k2,v2 �� 0 <= i2,j2,k2 <= 19, v2ֵΪ0��1
���
��ÿ�����ݣ������3�У�ÿ��20λ��ÿλΪ1����0������߳�Ϊ��0λ
��һ�У� �� k1,k2 ... knλΪ1������λΪ0��
�ڶ��У� ����һ���еĵ� i1,j1,k1λ��Ϊ v1,����λ����
�����У� ���ڶ����еĵ�i2λ��k2λ��Ϊv2������λ����
��������
4
0 1 2 8
7 19 0 1
7 2 8 0
1
1
1 1 1 0
1 1 1 1
�������
11100000100000000000
11100001100000000001
11100000000000000001
01000000000000000000
00000000000000000000
01000000000000000000
��ʾ
�Ƽ�ʹ���ڲ��࣬�ڲ�����ʹ�����ó�Ա�����ó�ԱҪ�ڹ��캯���г�ʼ����*/

#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
	char a[bitNum / 8 + 1];
	MyBitset() { memset(a, 0, sizeof(a)); };
	void Set(int i, int v) { 
		char& c = a[i / 8];
		int bp = i % 8;
		if (v)
			c |= (1 << bp);
		else
			c &= ~(1 << bp);
	}
	// �ڴ˴�������Ĵ���
	bool has_func = false;//��û�е��ù�[] �Ͱ����浽bits��
	class each_bit {
		int bit;
	public:
		each_bit operator=(int n) {
			bit = n;
			return *this;
		}
		friend ostream& operator <<(ostream& os, each_bit b) {
			os << b.bit;
			return os;
		}
	}bits[bitNum+1];
	each_bit& operator [](int i) {
		if (!has_func) {
			for (int i = 0; i < bitNum; ++i) {
				bits[i] = (a[i / 8] >> (i % 8)) & 1;
			}
			has_func = true;
		}
		return bits[i];
	}
	void Print() {
		for (int i = 0; i < bitNum; ++i)
			cout << (*this)[i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i, j, k, v;
	while (cin >> n) {
		MyBitset<20> bs;
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t, 1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}
