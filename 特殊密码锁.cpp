/*����
��һ������Ķ���������������n�������İ�ť��ɣ�n<30������ť�а�/͹����״̬�����ְ���ť��ı���״̬��

Ȼ������ͷ�۵��ǣ����㰴һ����ťʱ���������ڵ�������ť״̬Ҳ�ᷴת����Ȼ������㰴��������������ұߵİ�ť���ð�ťֻ��Ӱ�쵽�������ڵ�һ����ť��

��ǰ������״̬��֪����Ҫ����������ǣ���������Ҫ�����ٴΰ�ť�����ܽ�������ת��Ϊ��������Ŀ��״̬��

����
���У�����������0��1��ɵĵȳ��ַ�������ʾ��ǰ/Ŀ��������״̬������0������1����͹��
���
������Ҫ���еİ���ť��������������޷�ʵ��ת�䣬�����impossible��
��������
011
000
�������
1*/

#include<iostream>
using namespace std;
int now[35];
int now2[35];
int goal[35];
int n = 0;
int ans = 100;
void push(int i) {//���µ�i����ť
	if (i == 0) {
		now[i] = 1 - now[i];
		now[i + 1] = 1 - now[i + 1];
		return;
	}
	if (i == n - 1) {
		now[i] = 1 - now[i];
		now[i - 1] = 1 - now[i - 1];
		return;
	}
	now[i - 1] = 1 - now[i - 1];
	now[i] = 1 - now[i];
	now[i + 1] = 1 - now[i + 1];
	return;
}
void push2(int i) {//���µ�i����ť
	if (i == 0) {
		now2[i] = 1 - now2[i];
		now2[i + 1] = 1 - now2[i + 1];
		return;
	}
	if (i == n - 1) {
		now2[i] = 1 - now2[i];
		now2[i - 1] = 1 - now2[i - 1];
		return;
	}
	now2[i - 1] = 1 - now2[i - 1];
	now2[i] = 1 - now2[i];
	now2[i + 1] = 1 - now2[i + 1];
	return;
}
bool check() {
	for (int i = 0; i < n; ++i) {
		if (now[i] != goal[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int lock[100];
	char ch;
	int p = 0;
	while (cin >> ch) {
		lock[p++] = ch-'0';
	}
	
	for (int i = 0; i < p / 2; ++i) {
		now[i] = lock[i];
		now2[i] = lock[i];
	}
	for (int i = 0; i < p / 2; ++i) {
		goal[i] = lock[i + p / 2];
	}
	n = p / 2;
	
	//ö������ߵĵư����� Ȼ��ʣ�µ���ô���Ϳ���ȷ����
	push(0);//���Ļ�
	int cnt1 = 1;
	for (int i = 1; i < n; ++i) {
		if (now[i - 1] != goal[i - 1]) {
			push(i);
			cnt1++;
		}
	}
	if (now[n - 1] == goal[n - 1]) {
		ans = cnt1;
	}

	//�����Ļ�
	cnt1 = 0;
	for (int i = 1; i < n; ++i) {
		if (now2[i - 1] != goal[i - 1]) {
			push2(i);
			cnt1++;
		}
	}
	if (now2[n - 1] == goal[n - 1]) {
		if (cnt1 < ans)
			ans = cnt1;
	}

	if (ans == 100) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
