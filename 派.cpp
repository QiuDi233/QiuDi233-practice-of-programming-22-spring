/*����
�ҵ�����Ҫ���ˣ�����ϰ�ף�����Ҫ��һЩ�ɷָ���ҡ�����N����ͬ��ζ����ͬ��С���ɡ���F�����ѻ����μ��ҵ��ɶԣ�ÿ���˻��õ�һ���ɣ�����һ���ɵ�һ�飬�����ɼ����ɵ�С��ƴ�ɣ�������һ�����ɣ���

�ҵ������Ƕ��ر�С������������õ������һ�飬�ͻῪʼ��Թ������������õ�������ͬ����С�ģ�������Ҫ��ͬ����״�ģ�����Ȼ������Щ�ɻᱻ�˷ѣ����ܱȸ��������ɶԺá���Ȼ����ҲҪ���Լ���һ�飬����һ��ҲҪ�������˵�ͬ����С��

��������ÿ�����õ���������Ƕ��٣�ÿ���ɶ���һ����Ϊ1���뾶���ȵ�Բ���塣

����
��һ�а�������������N��F��1 �� N, F �� 10 000����ʾ�ɵ����������ѵ�������
�ڶ��а���N��1��10000֮�����������ʾÿ���ɵİ뾶��
���
���ÿ�����ܵõ��������ɵ��������ȷ��С�������λ��
��������
3 3
4 3 3
�������
25.133*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
int n = 0, f = 0;
double v[10005];
bool cake(double x) {
	//�Ƿ����ÿ�˷ֵ����Ϊx�ĵ���
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += int(v[i] / x);
	}
	return cnt >= (f+1);
}
int main() {
	int r[10005];
	cin >> n >> f;
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	double left = 0;
	double right = 100000000;
	for (int i = 0; i < n; ++i) {
		v[i] = PI * r[i] * r[i];
		if (v[i] > right) {
			right = v[i];
		}
	}
	
	double mid = (left + right) / 2;//ÿ�����ѿ��Էֵ��ĵ������
	while (right-left>1e-6) {
		mid = (left + right) / 2;
		if (cake(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << fixed << setprecision(3) << mid << endl;
	return 0;
}
