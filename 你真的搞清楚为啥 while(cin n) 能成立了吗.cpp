#include <iostream>
using namespace std;
class MyCin
{
// �ڴ˴�������Ĵ���
	bool bStop;
public:
	MyCin():bStop(false){}
	operator bool(){//����bool��������� 
		return !bStop;
	}
	MyCin&operator>>(int &n){//����>> 
		if(bStop)
			return *this;
		cin>>n;
		if(n==-1) bStop=true;
		return *this;
	}

};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
