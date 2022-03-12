/*描述
补足MyString类，使程序输出指定结果
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}
输入
多组数据，每组一行，是两个不带空格的字符串
输出
对每组数据，先输出一行，打印输入中的第一个字符串三次
然后再输出一行，打印输入中的第二个字符串三次
样例输入
abc def
123 456
样例输出
abc,abc,abc
def,def,def
123,123,123
456,456,456*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char* p;
public:
	MyString(const char* s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;

	}
	~MyString() { if (p) delete[] p; }
	// 在此处补充你的代码
	MyString(const MyString& s) {//由于有MyString s2 = s1; 所以需要复制构造函数
		if (s.p) {
			p = new char[strlen(s.p) + 1];
			strcpy(p, s.p);
		}
		else
			p = NULL;

	}
	void Copy(const char* s) {
		if (s) {
			if (p) {
				delete[]p;//要把空间释放掉
			}
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;
	}
	friend ostream& operator<<(ostream& output, const MyString& S) {
		output << S.p;
		return output;
	}
	MyString& operator=(const MyString& s) {
		if (this == &s) {
			return *this;//如果是自己就不要进行操作 否则会把自己delete了 
		}
		if (s.p) {
			if (p) {
				delete[]p;//要把空间释放掉
			}
			p = new char[strlen(s.p) + 1];
			strcpy(p, s.p);
		}
		else
			p = NULL;
		return *this;
	}
};
int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}
