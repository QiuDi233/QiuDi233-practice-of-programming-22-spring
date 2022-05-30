/*����
Consider a regular triangular area, divide it into four equal triangles of half height and remove the one in the middle.
 Apply the same operation recursively to each of the three remaining triangles. If we repeated this procedure infinite times,
  we'd obtain something with an area of zero. The fractal that evolves this way is called the Sierpinski Triangle. 
  Although its topological dimension is 2, its Hausdorff-Besicovitch dimension is log(3)/log(2)~1.58, a fractional value 
  (that's why it is called a fractal). By the way, the Hausdorff-Besicovitch dimension of the Norwegian coast is approximately 1.52,
   its topological dimension being 1.


For this problem, you are to outline the Sierpinski Triangle up to a certain recursion depth, using just ASCII characters. 
Since the drawing resolution is thus fixed, you'll need to grow the picture appropriately. Draw the smallest triangle 
(that is not divided any further) with two slashes, to backslashes and two underscores like this:

 /\
/__\
To see how to draw larger triangles, take a look at the sample output.

����
The input contains several testcases. Each is specified by an integer n.
 Input is terminated by n=0. Otherwise 1<=n<=10 indicates the recursion depth.
���
For each test case draw an outline of the Sierpinski Triangle with a side's total length of 2n characters. 
Align your output to the left, that is, print the bottom leftmost slash into the first column. 
The output must not contain any trailing blanks. Print an empty line after each test case.
��������
3
2
1
0
�������
       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

   /\
  /__\
 /\  /\
/__\/__\

 /\
/__\*/ 

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
char tri[2050][2050];
void draw(int x,int y,int n) {//���½�������(x,y) ���Ϊn
	if (n == 1) {
		tri[x][y] = '/';
		tri[x + 1][y] = '_';
		tri[x + 2][y] = '_';
		tri[x + 3][y] = '\\';
		tri[x][y + 1] = ' ';
		tri[x + 1][y + 1] = '/';
		tri[x + 2][y + 1] = '\\';
		tri[x + 3][y + 1] = ' ';
	}
	else {
		draw(x, y, n - 1);
		draw(x + pow(2, n), y, n - 1);
		draw(x + pow(2, n - 1), y + pow(2, n - 1), n - 1);
	}
}
int main() {
	int n = 0;
	while (cin >> n) {
		if (n == 0)
			break;
		for (int i = 0; i < 2050; ++i) {
			for (int j = 0; j < 2050; ++j) {
				tri[i][j] = ' ';
			}
		}
		draw(0,0,n);
		for (int j = pow(2, n) - 1; j >= 0; --j) {
			for (int i = 0; i < pow(2, n+1); ++i) {
				cout << tri[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
