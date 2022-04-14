#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
	// �ڴ˴�������Ĵ���
public:
	class CArray2D {
	public:
		T* pp;//ָ��ĳһ�㿪ʼ��ָ�� 
		int _z;
		T* operator[](int n) {
			return pp + n * _z;
		}
		CArray2D(T *_p, int zz) {
			pp = _p;
			_z = zz;
		}
		operator T*() {
			return pp;
		}
	};
	//T*p;//��ά�������ʼ��ַ ����λ����չ����һά����
	T* p;
	int x;
	int y;
	int z;//�����
	CArray3D(int xx, int yy, int zz) :x(xx), y(yy), z(zz) {
		p = new T[x * y * z];
	}
	~CArray3D() {
		delete []p;
	}
	CArray2D operator[](int n) {
		return CArray2D(p+n*(y*z),z);
	}

};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3, 2, 2);
void PrintA()
{
	for (int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";
			cout << endl;
		}
	}
}
void PrintB()
{
	for (int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k)
				cout << b[i][j][k] << ",";
			cout << endl;
		}
	}
}

int main()
{

	int No = 0;
	for (int i = 0; i < 3; ++i) {
		a[i];
		for (int j = 0; j < 4; ++j) {
			a[j][i];
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
			a[j][i][i];
		}
	}
	PrintA();
	memset(a[1], -1, 20 * sizeof(int));
	memset(a[1], -1, 20 * sizeof(int));
	PrintA();
	memset(a[1][1], 0, 5 * sizeof(int));
	PrintA();

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				b[i][j][k] = 10.0 / (i + j + k + 1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;

	return 0;
}
