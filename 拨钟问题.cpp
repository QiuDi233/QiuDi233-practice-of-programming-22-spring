/*����
��9��ʱ�ӣ��ų�һ��3*3�ľ���

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I    
(ͼ 1)
������Ҫ�����ٵ��ƶ�����9��ʱ�ӵ�ָ�붼����12���λ�á���������9�ֲ�ͬ���ƶ������±���ʾ��ÿ���ƶ��Ὣ���ɸ�ʱ�ӵ�ָ����˳ʱ�뷽�򲦶�90�ȡ�



�ƶ�    Ӱ���ʱ��
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
����
9����������ʾ��ʱ��ָ�����ʼλ�ã�������������֮���õ����ո���������У�0=12�㡢1=3�㡢2=6�㡢3=9�㡣
���
���һ����̵��ƶ����У�ʹ��9��ʱ�ӵ�ָ�붼ָ��12�㡣�����ƶ�����Ŵ�С������������������������֮���õ����ո������
��������
3 3 0 
2 2 2 
2 1 2 
�������
4 5 8 9 */



#include<iostream>
using namespace std;
int clock1[15];
void move(int i, int n) {
	if (i == 1) {
		clock1[0] = (clock1[0] + n) % 4;
		clock1[1] = (clock1[1] + n) % 4;
		clock1[3] = (clock1[3] + n) % 4;
		clock1[4] = (clock1[4] + n) % 4;
	}
	if (i == 2) {
		clock1[0] = (clock1[0] + n) % 4;
		clock1[1] = (clock1[1] + n) % 4;
		clock1[2] = (clock1[2] + n) % 4;
	}
	if (i == 3) {
		clock1[1] = (clock1[1] + n) % 4;
		clock1[2] = (clock1[2] + n) % 4;
		clock1[4] = (clock1[4] + n) % 4;
		clock1[5] = (clock1[5] + n) % 4;
	}
	if (i == 4) {
		clock1[0] = (clock1[0] + n) % 4;
		clock1[3] = (clock1[3] + n) % 4;
		clock1[6] = (clock1[6] + n) % 4;
	}
	if (i == 5) {
		clock1[1] = (clock1[1] + n) % 4;//B
		clock1[3] = (clock1[3] + n) % 4;//D
		clock1[4] = (clock1[4] + n) % 4;//E
		clock1[5] = (clock1[5] + n) % 4;//F
		clock1[7] = (clock1[7] + n) % 4;//H
	}
	if (i == 6) {
		clock1[2] = (clock1[2] + n) % 4;//C
		clock1[5] = (clock1[5] + n) % 4;//F
		clock1[8] = (clock1[8] + n) % 4;//I
	}
	if (i == 7) {
		clock1[3] = (clock1[3] + n) % 4;//D
		clock1[4] = (clock1[4] + n) % 4;//E
		clock1[6] = (clock1[6] + n) % 4;//G
		clock1[7] = (clock1[7] + n) % 4;//H
	}
	if (i == 8) {
		clock1[6] = (clock1[6] + n) % 4;//G
		clock1[7] = (clock1[7] + n) % 4;//H
		clock1[8] = (clock1[8] + n) % 4;//I
	}
	if (i == 9) {
		clock1[4] = (clock1[4] + n) % 4;//E
		clock1[5] = (clock1[5] + n) % 4;//F
		clock1[7] = (clock1[7] + n) % 4;//H
		clock1[8] = (clock1[8] + n) % 4;//I
	}
}
bool check() {
	for (int i = 0; i < 9; ++i) {
		if (clock1[i])
			return false;
	}
	return true;
}
int main() {

	for (int i = 0; i < 9; ++i) {
		cin >> clock1[i];
	}
	int index[15];
	int ans = 100;
	for (int i1 = 0; i1 < 4; ++i1) {
		for (int i2 = 0; i2 < 4; ++i2)
			for (int i3 = 0; i3 < 4; ++i3)
				for (int i4 = 0; i4 < 4; ++i4)
					for (int i5 = 0; i5 < 4; ++i5)
						for (int i6 = 0; i6 < 4; ++i6)
							for (int i7 = 0; i7 < 4; ++i7)
								for (int i8 = 0; i8 < 4; ++i8)
									for (int i9 = 0; i9 < 4; ++i9) {
										move(1, i1);
										move(2, i2);
										move(3, i3);
										move(4, i4);
										move(5, i5);
										move(6, i6);
										move(7, i7);
										move(8, i8);
										move(9, i9);
										if (check() && i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 < ans) {
											ans = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
											index[1] = i1;
											index[2] = i2;
											index[3] = i3;
											index[4] = i4;
											index[5] = i5;
											index[6] = i6;
											index[7] = i7;
											index[8] = i8;
											index[9] = i9;
										}
										move(1, -i1);
										move(2, -i2);
										move(3, -i3);
										move(4, -i4);
										move(5, -i5);
										move(6, -i6);
										move(7, -i7);
										move(8, -i8);
										move(9, -i9);
									}

	}
	for (int i = 1; i <= 9; ++i) {
		for (int j = 0; j < index[i]; j++) {
			cout << i << " ";
		}
	}
	return 0;
}
