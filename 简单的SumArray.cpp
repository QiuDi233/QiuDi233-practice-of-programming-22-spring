/*����
��дģ�� PrintArray,ʹ�ó����������ǣ� TomJackMaryJohn 10 ���ñ�дSumArray����

#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
// �ڴ˴�������Ĵ���
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //��ʾ��1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}
����
��
���
TomJackMaryJohn
10
��������
��
�������
TomJackMaryJohn
10*/

#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* t1, T* t2){
	T tmp=(*t1);
	for (T* t = t1+1; t < t2; ++t) {
		tmp += *t;
	}
	return tmp;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John" };
	cout << SumArray(array, array + 4) << endl;
	int a[4] = { 1, 2, 3, 4 };  //��ʾ��1+2+3+4 = 10
	cout << SumArray(a, a + 4) << endl;
	return 0;
}
