/*ʵ��һ��ѧ����Ϣ������򣬼���һ��ѧ��������ƽ���ɼ���

Ҫ��ʵ��һ������ѧ�����࣬�����������г�Ա�������ǡ�˽�еġ���

�������г����е� Student ����ʵ���������ܡ�

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// �ڴ˴�������Ĵ���
};

int main() {
	Student student;        // ������Ķ���
	student.input();        // ��������
	student.calculate();    // ����ƽ���ɼ�
	student.output();       // �������
}
����
��������Ϊһ�У�������
����,����,ѧ��,��һѧ��ƽ���ɼ�,�ڶ�ѧ��ƽ���ɼ�,����ѧ��ƽ���ɼ�,����ѧ��ƽ���ɼ���
��������Ϊ����ĸ�Ϳո���ɵ��ַ��������뱣֤����������20���ַ������ҿո񲻻�������ַ������ˣ������䡢ѧ�ź�ѧ��ƽ���ɼ���Ϊ�Ǹ���������Ϣ֮���ö��Ÿ�����
���
���һ�����ݣ�������
����,����,ѧ��,����ƽ���ɼ���
��Ϣ֮���ö��Ÿ�����
��������
Tom Hanks,18,7817,80,80,90,70
�������
Tom Hanks,18,7817,80
��ʾ
��������ʵ�֣��������г�Ա��������˽�еġ�
�������У�����ƽ���ɼ���һ��Ϊ������*/ 
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// �ڴ˴�������Ĵ���
	private:
		char ch;
		char name[20];
		int age;
		int id;
		double grade[4];
		double aver;
	public:
		void input(){
			cin.get(name,21,',');
			cin>>ch>>age>>ch>>id>>ch>>grade[0]>>ch>>grade[1]>>ch>>grade[2]>>ch>>grade[3];
			return;
		}
		void calculate(){
			aver=(grade[0]+grade[1]+grade[2]+grade[3])/4;
			return;
		}
		void output(){
			cout<<name<<","<<age<<","<<id<<","<<aver<<endl;
			return;
		}
};

int main() {
	Student student;        // ������Ķ���
	student.input();        // ��������
	student.calculate();    // ����ƽ���ɼ�
	student.output();       // �������
}
