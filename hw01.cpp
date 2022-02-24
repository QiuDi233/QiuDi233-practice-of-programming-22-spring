/*编程：编写一个程序，从命令行读入一组参数，其中(可执行程序名后)第一个参数和最后一个参数分别是一个整数，请输出这两个整数的和。*/
#include<iostream>
#include<stdlib.h> 
using namespace std;
int main(int argc,char*argv[]){
	printf("%d",atoi(argv[1])+atoi(argv[argc-1]));
	return 0;
}
