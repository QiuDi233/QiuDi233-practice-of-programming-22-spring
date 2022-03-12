/*����
������գ����ָ�����

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// �ڴ˴�������Ĵ���
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
����
�������ݣ�ÿ�������������Ǹ�����s�� n��s������200λ�� n��int�ܱ�ʾ
���
��ÿ�����ݣ����6�У����ݷֱ��ǣ�
��������
99999999999999999999999999888888888888888812345678901234567789 12
6 6
�������
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14*/

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
	// �ڴ˴�������Ĵ���
private:
	char num[2*MAX];//����װ 
public:
	CHugeInt() {
		memset(num, 0, sizeof(num));
	}
	CHugeInt(char* s) {
		memset(num, 0, sizeof(num));
		for (int i = 0; i < strlen(s); ++i) {
			num[i] = s[strlen(s) - 1 - i];
		}
	}
	CHugeInt(int n) {
		memset(num, 0, sizeof(num));
		int i = 0;
		while (n != 0) {
			num[i] = n % 10 + '0';
			n /= 10;
			i++;
		}
	}
	friend ostream& operator <<(ostream &output, const CHugeInt& i){
		char tmp[2*MAX];
		memset(tmp, 0, sizeof(tmp));
		for (int k = 0; k < strlen(i.num); ++k) {
			tmp[k] = i.num[strlen(i.num) - 1 - k];
		}
		tmp[strlen(i.num)] = '\0';
		output << tmp;
		return output;
	
	}
	CHugeInt operator+(const CHugeInt& i) {
		int carry = 0;//��λ
		int p = 0;
		CHugeInt ans;

		while (p < strlen(num) && p < strlen(i.num)) {
			int n = (num[p] - '0' + i.num[p] - '0') + carry;
			ans.num[p] = n % 10 + '0';
			carry = n / 10;
			p++;
		}
		while (p < strlen(num)) {
			int n = (num[p] - '0') + carry;
			ans.num[p] = n % 10 + '0';
			carry = n / 10;
			p++;
		}
		while (p < strlen(i.num)) {
			int n = (i.num[p] - '0') + carry;
			ans.num[p] = n % 10 + '0';
			carry = n / 10;
			p++;
		}
		if (carry) {
			ans.num[p] = carry + '0';
		}
		return ans;
	}
	friend CHugeInt operator+(int n,CHugeInt i) {
		return CHugeInt(n) + i;
	}
	CHugeInt& operator+=(int n) {
		*this = *this + n;
		return *this;
	}
	CHugeInt& operator++() {
		*this = *this + 1;
		return *this;
	}
	CHugeInt operator++(int i) {
		CHugeInt tmp(*this);
		*this = *this + 1;
		return tmp;
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
