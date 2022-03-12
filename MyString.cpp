/*����
����MyString�࣬ʹ�������ָ�����
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
// �ڴ˴�������Ĵ���
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
����
�������ݣ�ÿ��һ�У������������ո���ַ���
���
��ÿ�����ݣ������һ�У���ӡ�����еĵ�һ���ַ�������
Ȼ�������һ�У���ӡ�����еĵڶ����ַ�������
��������
abc def
123 456
�������
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
	// �ڴ˴�������Ĵ���
	MyString(const MyString& s) {//������MyString s2 = s1; ������Ҫ���ƹ��캯��
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
				delete[]p;//Ҫ�ѿռ��ͷŵ�
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
			return *this;//������Լ��Ͳ�Ҫ���в��� �������Լ�delete�� 
		}
		if (s.p) {
			if (p) {
				delete[]p;//Ҫ�ѿռ��ͷŵ�
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
