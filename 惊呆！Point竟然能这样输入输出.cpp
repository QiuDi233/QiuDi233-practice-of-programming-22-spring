/*描述
程序填空
#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
输入
多组数据，每组两个整数
输出
对每组数据，输出一行，就是输入的两个整数
样例输入
2 3
4 5
样例输出
2,3
4,5*/


#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
	//重载输入和输出运算符 
	friend istream &operator>>(istream&input,Point&p){
		input>>p.x>>p.y;
		return input;
	}
	friend ostream &operator<<(ostream&output,const Point &p){
		output<<p.x<<","<<p.y;
		return output;
	}
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
