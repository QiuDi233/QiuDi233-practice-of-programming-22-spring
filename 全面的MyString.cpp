/*����
������գ����ָ�����

#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// �ڴ˴�������Ĵ���
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1�Ĵ��±�0��ʼ����Ϊ4���Ӵ�
	cout << s1(0,4) << endl;
	//s1�Ĵ��±�5��ʼ����Ϊ10���Ӵ�
	cout << s1(5,10) << endl;
	return 0;
}
����
��
���
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
��������
��
�������
1. abcd-efgh-abcd-
2. abcd-
3. 
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-*/

#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// �ڴ˴�������Ĵ���
	private:
		char *p;
	public:
		MyString(const char*s){//���ι��캯�� 
			if(s){
				p=new char[strlen(s)+1];
				strcpy(p,s);
			}
			else p=NULL;
		}
		MyString(){//�޲ι��캯��
			 p=NULL;
		}
		~MyString(){
			if(p) delete[]p;
		}
		MyString(const MyString &s){
			//���ƹ��캯��
			if(s.p){
				p=new char[strlen(s.p)+1];
				strcpy(p,s.p);
			}
			else
				p=NULL;
		}
		bool operator <(const MyString &s){
			return (strcmp(p,s.p)<0);
		}
		bool operator >(const MyString &s){
			return (strcmp(p,s.p)>0);
		}
		friend ostream&operator<<(ostream &output,const MyString&s){
			if(s.p){
				output<<s.p;
			}
			return output;
		} 
		bool operator ==(const MyString&s){
			return (strcmp(p,s.p)==0);
		} 
		MyString&operator=(const MyString &s){//��� 
			if(this==&s){
				return *this;
			}
			if(s.p){
				if(p){
					delete[]p;
				}
				p=new char[strlen(s.p)+1];
				strcpy(p,s.p);
			}
			else{
				p=NULL;
			}
			return *this;
		}
		friend MyString operator +(const MyString &s1,const MyString &s2){
			char *ss1=new char[strlen(s1.p)+strlen(s2.p)];
			strcpy(ss1,s1.p);
			strcat(ss1,s2.p);
			return MyString(ss1);
		}
		char& operator[](int n){
			return p[n];
		}
		MyString& operator+=(const char*s){
			MyString ss(s);
			*this=*this+ss;
			return *this;
		}
		MyString operator()(int x,int len){
			char *s=new char[len+1];
			for(int i=0;i<len;++i){
				s[i]=p[i+x];
			}
			return MyString(s);
		}
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1�Ĵ��±�0��ʼ����Ϊ4���Ӵ�
	cout << s1(0,4) << endl;
	//s1�Ĵ��±�5��ʼ����Ϊ10���Ӵ�
	cout << s1(5,10) << endl;
	return 0;
} 
