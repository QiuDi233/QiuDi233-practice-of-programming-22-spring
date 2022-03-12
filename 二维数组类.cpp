/*����
дһ����ά������ Array2,ʹ�����������������ǣ�

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

����

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// �ڴ˴�������Ĵ���
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
����
��
���
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
��������
None
�������
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,*/

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
	// �ڴ˴�������Ĵ���
private:
	int row;//�� 
	int col;// ��
	int** p;
public:
	Array2() {
		row = 0;
		col = 0;
		p = NULL;
	}
	Array2(int i, int j) {
		row = i;
		col = j;
		p = new int* [i];
		for (int k = 0; k < i; ++k) {
			*(p + k) = new int[j];
		}
	}
	~Array2() {
		for (int i = 0; i < row; ++i) {
			delete[] * (p + i);
		}
		delete[]p;
	}
	int operator()(int i, int j) {
		return *(*(p + i) + j);
	}
	int* operator[](int i) {
		return *(p+i);//ֻ���ص�һά �ڶ�ά��ԭ����[]�Ϳɵõ� 
	}
	Array2& operator=(const Array2& a)
	{
		if (p) {
			for (int i = 0; i < row; ++i) {
				delete[] * (p + i);
			}
			delete[]p;
		}
		if (&a == this) {
			return *this;
		}
		row = a.row;
		col = a.col;
		p = new int* [a.row];
		for (int k = 0; k < row; ++k) {
			*(p + k) = new int[a.col];
			memcpy(*(p + k), *(a.p + k), a.col*sizeof(int));//ע�����һ���������ֽڵĳ��� ����ĳ���͵ĸ���
		}
		return *this;
	}
};

int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;   
	b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}

