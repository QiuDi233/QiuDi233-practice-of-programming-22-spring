/*描述
程序填空，按要求输出

#include <iostream>
#include <vector>
using namespace std;

class A {
    static int count;
public:
// 在此处补充你的代码
static int theNumberOfA() {
        return count;
    }
};

int A::count = 0;

int main() {
    vector<A> v;
    
    for(int i = 0; i < 3; i++) {
        {
            A a;
            v.push_back(a);
        }
        cout << A::theNumberOfA() << endl;
    }

    return 0;
}
输入
无
输出
如样例
样例输入
无
样例输出
1
2
3*/

#include <iostream>
#include <vector>
using namespace std;

class A {
    static int count;
public:
// 在此处补充你的代码
	A(){
		count++;
	} 
static int theNumberOfA() {
        return count;
    }
};

int A::count = 0;

int main() {
    vector<A> v;
    
    for(int i = 0; i < 3; i++) {
        {
            A a;
            v.push_back(a);
        }
        cout << A::theNumberOfA() << endl;
    }

    return 0;
}
