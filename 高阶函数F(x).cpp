/*����
lisp�������и߽׺����ĸ��������������Ϊ�����Ĳ�����Ҳ������Ϊ�����ķ���ֵ������:

(define (f n)   (lambda (x) (+ x n)))

������һ������f���ú����ķ���ֵ����һ���������ٶ���Ϊg�� (lambda (x) (+ x n) �˺��������ǲ���Ϊx������ֵΪx + n�� ���� ((f 7) 9)   ����ִ��

(f 7)�Բ���7����f, f�ķ���ֵ��g,n��ֵΪ7

((f 7) 9)�ȼ��� (g 9)�����Բ���9����g�� �� n = 7, x = 9 ,���(g 9)����ֵΪ16

��дһ��C++��ͨ�ú���ģ��f,ʹ֮�����������lisp����f�Ĺ��ܡ� ��������ĳ�����������

16
world hello!
world!

#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
int main()
{
   cout << f<int,int>(7)(9) << endl;   //16
   cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
   cout << f<char,string> ('!')("world") << endl;
   
   
   return 0;    //world!
}
����
��
���
16
world hello!
world!
��������
��
�������
16
world hello!
world!
��ʾ
C++����ģ��ʵ����ʱ��Ҳ����ͨ����<>��ָ�����Ͳ�������Ӧ�ľ���������ʵ�֡�*/ 

/*����
lisp�������и߽׺����ĸ��������������Ϊ�����Ĳ�����Ҳ������Ϊ�����ķ���ֵ������:

(define (f n)   (lambda (x) (+ x n)))

������һ������f���ú����ķ���ֵ����һ���������ٶ���Ϊg�� (lambda (x) (+ x n) �˺��������ǲ���Ϊx������ֵΪx + n�� ���� ((f 7) 9)   ����ִ��

(f 7)�Բ���7����f, f�ķ���ֵ��g,n��ֵΪ7

((f 7) 9)�ȼ��� (g 9)�����Բ���9����g�� �� n = 7, x = 9 ,���(g 9)����ֵΪ16

��дһ��C++��ͨ�ú���ģ��f,ʹ֮�����������lisp����f�Ĺ��ܡ� ��������ĳ�����������

16
world hello!
world!

#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
int main()
{
   cout << f<int,int>(7)(9) << endl;   //16
   cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
   cout << f<char,string> ('!')("world") << endl;


   return 0;    //world!
}
����
��
���
16
world hello!
world!
��������
��
�������
16
world hello!
world!
��ʾ
C++����ģ��ʵ����ʱ��Ҳ����ͨ����<>��ָ�����Ͳ�������Ӧ�ľ���������ʵ�֡�*/

#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
template<class T1, class T2>
class f {
public:
	T1 t;
	f(T1 t_) {
		t = t_;
	}
	auto operator ()(T2 t_) {
		return t_+ t;
	}
};
int main()
{
	cout << f<int, int>(7)(9) << endl;   //16
	cout << f<string, string>(" hello!")("world") << endl; // world hello!
	cout << f<char, string>('!')("world") << endl;


	return 0;    //world!
}
