/*����
��ȫ���룬ʹ���н��Ϊ�� Buy Nothing Pay Beef Buy Meat Pay Beef

#include<bits/stdc++.h>
using namespace std;

class Food {
public:
// �ڴ˴�������Ĵ���
};

class Meat : public Food {
public:
	void Buy() { cout << "Buy Meat" << endl; }
	virtual void Pay() { cout << "Pay Meat" << endl; }
};

class Beef : public Meat {
public:
	void Buy() { cout << "Buy Beef" << endl; }
	void Pay() { cout << "Pay Beef" << endl; }
};
int main() {
	Beef bf;
	Meat* pmt = &bf;
	Food* pfd = &bf;

	pfd->Buy();
	pfd->Pay();
	pmt->Buy();
	pmt->Pay();
	return 0;
}
����
��
���
Buy Nothing
Pay Beef
Buy Meat
Pay Beef
��������
��
�������
Buy Nothing
Pay Beef
Buy Meat
Pay Beef*/

#include<bits/stdc++.h>
using namespace std;

class Food {
public:
// �ڴ˴�������Ĵ���
	void Buy(){
		cout<<"Buy Nothing"<<endl;
	}
	virtual void Pay(){
		
	}
};

class Meat : public Food {
public:
	void Buy() { cout << "Buy Meat" << endl; }
	virtual void Pay() { cout << "Pay Meat" << endl; }
};

class Beef : public Meat {
public:
	void Buy() { cout << "Buy Beef" << endl; }
	void Pay() { cout << "Pay Beef" << endl; }
};
int main() {
	Beef bf;
	Meat* pmt = &bf;
	Food* pfd = &bf;

	pfd->Buy();
	pfd->Pay();
	pmt->Buy();
	pmt->Pay();
	return 0;
}
