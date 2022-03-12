/*描述
程序填空，输出指定结果

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
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
输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
输出
对每组数据，输出6行，内容分别是：
样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6
样例输出
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
	// 在此处补充你的代码
private:
	char num[2*MAX];//反着装 
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
		int carry = 0;//进位
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
