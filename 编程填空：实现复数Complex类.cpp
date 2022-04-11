/*描述
实现复数Complex类，使输出结果为：

3+2i
3+2i
-15
-12+2i
0
5+12i
-12+2i
2i
5+12i



#include <iostream>
using namespace std;
// 在此处补充你的代码
int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}
输入
无
输出
3+2i
3+2i
-15
-12+2i
0
5+12i
-12+2i
2i
5+12i
样例输入
无
样例输出
3+2i
3+2i
-15
-12+2i
0
5+12i
-12+2i
2i
5+12i*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
class Complex {
public:
	int r;
	int i;
	Complex(const char num[]) {
		r = num[0] - '0';
		i = num[2] - '0';
	}
	Complex(int r_=0, int i_ = 0) :r(r_), i(i_) {	}
	friend ostream& operator <<(ostream& os, Complex c) {
		if (c.r == 0 && c.i == 0)
			os << 0;
		else if (c.r == 0)
			os << c.i << "i";
		else if (c.i == 0)
			os << c.r;
		else
			os << c.r << "+" << c.i << "i";
		return os;
	}
	Complex operator +(Complex b) {
		return Complex(r + b.r, i + b.i);
	}
	Complex operator -(Complex b) {
		return Complex(r - b.r, i - b.i);
	}
	Complex operator *(Complex b) {
		return Complex(r * b.r - i * b.i, r * b.i + i * b.r);
	}
	Complex operator+=(Complex b) {
		r += b.r;
		i += b.i;
		return *this;
	}
	Complex operator-=(Complex b) {
		r -= b.r;
		i -= b.i;
		return *this;
	}
	Complex operator*=(Complex b) {
		*this = *this * b;
		return *this;
	}
};
int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}
