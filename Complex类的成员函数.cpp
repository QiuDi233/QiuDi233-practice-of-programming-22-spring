/*����
������������ǣ�

3+4i

5+6i

�벹��Complex��ĳ�Ա���������ܼӳ�Ա������

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// �ڴ˴�������Ĵ���
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
����
��
���
3+4i
5+6i
��������
None
�������
3+4i
5+6i*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// �ڴ˴�������Ĵ���
Complex& operator=(string s){
	int rr=0;
	int ii=0;
	char ch;
	//sccanf(s,"%d %c %d %c",rr,ch,ii,ch); ûsscanf��ͷ�ļ��ò���
	int j;
	for(j=0;j<s.size()&&s[j]!='+';++j){
		rr*=10;
		rr+=s[j]-'0';
	}
	j++;
	for(;j<s.size()&&s[j]!='i';++j){
		ii*=10;
		ii+=s[j]-'0'; 
	}
	r=rr;
	i=ii;
	return *this;
}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
