# practice-of-programming-22-spring
2022 程序设计实习
我把作业写了一下 放在了branch里面

### cmp函数模板
我是开了个计数器记录函数调用次数
助教给出的更优雅的做法是这样的

template <class T>
	
void cmp(const T& x, T& y)
{
	
	cout << "b" << endl;
}
	
template <class T>
	
void cmp(T& x, const T& y)
{
	
	cout << "a" << endl;
	
}
	
template <class T>
	
void cmp(T* x, const T& y)
{
	
	cout << "c" << endl;
	
}
 
