/*描述
有9个时钟，排成一个3*3的矩阵。

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
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。



移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。
输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。
样例输入
3 3 0 
2 2 2 
2 1 2 
样例输出
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
