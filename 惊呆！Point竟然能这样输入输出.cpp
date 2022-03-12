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
