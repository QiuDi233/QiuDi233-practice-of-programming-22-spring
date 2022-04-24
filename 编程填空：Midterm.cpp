/*描述
填写缺失的部分，使程序输出要求的结果。

#include<iostream>
using namespace std;

class Midterm {
private:
  int val; 
public:
// 在此处补充你的代码
};

int Min(int a,int b) {
  if(a < b)
    return a;
  else
    return b;
}
int main(){
  Midterm a; 
  cout << a << endl;
  cout << a + 2021 << endl;
  Midterm b(1000);
  cout << b ++ << endl; 
  ((b-=10)-=20)-=30;
  cout << b ++ << endl; 
  cout << Min(255,b) <<endl;
  return 0;
}
输入
.
输出
.
样例输入
(无)
样例输出
0
2021
1001
942
255*/

#include<iostream>
using namespace std;

class Midterm {
private:
  int val; 
public:
// 在此处补充你的代码
	Midterm(int v):val(v+1){	}
	Midterm():val(0){ 	}
	int operator+(int n){
		return val+n;
	}
	Midterm operator++(int n){
		Midterm tmp=*this;
		val++;
		return tmp;
	}
	friend ostream&operator<<(ostream&os,Midterm m){
		os<<m.val;
		return os;
	}
	Midterm&operator-=(int n){
		val-=n;
		return *this;
	}
	operator int(){
		return val;
	}
};

int Min(int a,int b) {
  if(a < b)
    return a;
  else
    return b;
}
int main(){
  Midterm a; 
  cout << a << endl;
  cout << a + 2021 << endl;
  Midterm b(1000);
  cout << b ++ << endl; 
  ((b-=10)-=20)-=30;
  cout << b ++ << endl; 
  cout << Min(255,b) <<endl;
  return 0;
}
