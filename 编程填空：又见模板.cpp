/*����
��д���룬��Ҫ����������

#include <iostream>
#include <string>
using namespace std;
// �ڴ˴�������Ĵ���
int main() {
	
	int t;
	cin >> t;
	while( t -- ) { 
	    int b1[10];
	    for(int i = 0;i < 10; ++i) 	
	
	    	cin >> b1[i];
	    A<int, 10> a1 = b1;
	    cout << a1[2] << endl;
	    
	
	    double b2[5] ;
	    for(int i = 0;i < 5; ++i) 	
	    	cin >> b2[i];
	    
	    A<double, 5> a2 = b2;
	    cout << a2.sum() << endl;
	
		
	    string b3[4] ;
	    for(int i = 0;i < 4; ++i) 	
	    	cin >> b3[i];
	    
	    A<string, 4> a3 = b3;
	    cout << a3.sum() << endl;
	}
	return 0;
}
����
��һ��������n����ʾ��n������
ÿ��������3��
��һ����10������
�ڶ�����5��С��
��������4�������ո���ַ���������֮���ÿո�ָ�
���
�����10����������ĵ�����
�����5��С���ĺ� (���ÿ���С������漸λ����coutֱ��������ɣ�
�����4���ַ�������һ����ַ���
��������
1
1 2 3 4 5 6 7 8 9 10
4.2 0.0 3.1 2.7 5.2
Hello , world !
�������
3
15.2
Hello,world!*/

#include <iostream>
#include <string>
using namespace std;
// �ڴ˴�������Ĵ���
template<class T,int num>
class A{
public:
	T t[20];

	A(T*b){
		for(int i=0;i<num;++i){
			t[i]=b[i];
		}
	}
	T operator [](int i){
		return t[i];
	}
	T sum(){
		T tt=t[0];
		for(int i=1;i<num;++i){
			tt+=t[i];
		}
		return tt;
	}
};
int main() {
	
	int t;
	cin >> t;
	while( t -- ) { 
	    int b1[10];
	    for(int i = 0;i < 10; ++i) 	
	
	    	cin >> b1[i];
	    A<int, 10> a1 = b1;
	    cout << a1[2] << endl;
	    
	
	    double b2[5] ;
	    for(int i = 0;i < 5; ++i) 	
	    	cin >> b2[i];
	    
	    A<double, 5> a2 = b2;
	    cout << a2.sum() << endl;
	
		
	    string b3[4] ;
	    for(int i = 0;i < 4; ++i) 	
	    	cin >> b3[i];
	    
	    A<string, 4> a3 = b3;
	    cout << a3.sum() << endl;
	}
	return 0;
}
