/*����
Lisp�������и߽׺����ĸ��������������Ϊ�����Ĳ�����Ҳ������Ϊ�����ķ���ֵ������:

(define (square x)  (* xx))   ������һ����x��ƽ���ĺ���

(define (inc x)  (+ x1))     ������һ����x+1�ĺ���

(define (combine f g)      (lambda (x) (f (+ (fx) (g x)))))

(combine f g) ���غ���k , k(x) = f( f(x)+g(x))

��� ((combine square inc) 3) �ķ���ֵ����169

�˴�

f(x) = x*x      g(x) = x + 1

k(x) = (x*x+(x+1)) ^2

((combine square inc) 3) ���� k(3)

��˷���ֵΪ169 ��C++ʵ�����Ƶ�combine����ģ�壬ʹ������ĳ���������Ϊ

169
10.75

#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
int main()
{
    auto Square = [] (double a) { return a * a; };
    auto Inc = [] (double a) { return a + 1; };
    cout << combine<decltype(Square),decltype(Inc),int>(Square,Inc)(3) << endl;
    cout << combine<decltype(Inc),decltype(Square),double>(Inc,Square)(2.5) << endl;

    return 0;
}
����
��
���
169
10.75
��������
��
�������
169
10.75
��ʾ
C++����ģ��ʵ����ʱ��Ҳ����ͨ����<>��ָ�����Ͳ�������Ӧ�ľ���������ʵ�֡�*/ 

#include <iostream>
using namespace std;
// �ڴ˴�������Ĵ���
template<class T1, class T2, class T3>
class combine {
	T1 f;
	T2 g;
public:
	combine(T1 f_, T2 g_):f(f_),g(g_) {
		
	}
	auto operator ()(T3 n) {
		return f(f(n) + g(n));
	}
};
int main()
{
    auto Square = [] (double a) { return a * a; };
    auto Inc = [] (double a) { return a + 1; };
    cout << combine<decltype(Square),decltype(Inc),int>(Square,Inc)(3) << endl;
    cout << combine<decltype(Inc),decltype(Square),double>(Inc,Square)(2.5) << endl;

    return 0;
}
