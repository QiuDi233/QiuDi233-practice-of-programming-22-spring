#include <iostream>
#include <string>
/*����
ѧ�����ڼ�¼��ѯ�����������������������

1)add date id������add 1 1500012755��ѧ��Ϊ1500012755��ѧ�����ڱ���1��ȱ��

2)querydate_begin date_end������query 1 3����ѯ����1��������3�գ�����1�ռ�3�գ�ȱ��ѧ�������������ʽΪ��ͬһ����ȱ�ڵ�ѧ�����˳����add����˳��һ�£���

date id id ����

date id ����

3)exit ��������

��ʵ��QueryResult������



#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
// �ڴ˴�������Ĵ���
int main(int argc, char* argv[])
{
	map<int, list<int> > Attendance;
	map<int, list<int> >::iterator it;
	string cmd;
	int date, id, date_lower, date_upper;
	while (cin >> cmd){
		if (cmd == "add"){
			cin >> date >> id;
			it = Attendance.find(date);
			if (it != Attendance.end()){
				it->second.push_back(id);
			}
			else{
				list<int> lst_id;
				lst_id.push_back(id);
				Attendance.insert(make_pair(date,lst_id));
			}
		}
		else if (cmd == "query"){
			cin >> date_lower>>date_upper;
			QueryResult(Attendance.lower_bound(date_lower), Attendance.upper_bound(date_upper));
		}
		else if (cmd == "exit")
			return 0;
	}
	return 0;
}
����
ÿһ�����ݸ�ʽ�����������������date��int�ͣ�0 < date < 32��idΪint�ͣ���15��ͷ��10λѧ�š�
���
������������query����ʱ�������Ӧ��ʽ��ȱ������(ÿ��ѧ�ź�����һ���ո�)
��������
add 1 1500012755
add 1 1500012796
add 3 1500012755
query 1 2
add 4 1500012737
query 1 4
exit
�������
1: 1500012755 1500012796
1: 1500012755 1500012796
3: 1500012755
4: 1500012737*/ 



#include <map>
#include <list>
using namespace std;
// �ڴ˴�������Ĵ���
void QueryResult(map<int,list<int> >::iterator it1,map<int,list<int> >::iterator it2){
	map<int,list<int> >::iterator it=it1;
	list<int>::iterator i1;
	
	for(it;it!=it2;++it){
		i1=it->second.begin();
		cout<<it->first<<":";
		for(i1;i1!=it->second.end();++i1){
			cout<<" "<<*i1;
		}
		cout<<endl;
	}
	return;
} 
int main(int argc, char* argv[])
{
	map<int, list<int> > Attendance;
	map<int, list<int> >::iterator it;
	string cmd;
	int date, id, date_lower, date_upper;
	while (cin >> cmd){
		if (cmd == "add"){
			cin >> date >> id;
			it = Attendance.find(date);
			if (it != Attendance.end()){
				it->second.push_back(id);
			}
			else{
				list<int> lst_id;
				lst_id.push_back(id);
				Attendance.insert(make_pair(date,lst_id));
			}
		}
		else if (cmd == "query"){
			cin >> date_lower>>date_upper;
			QueryResult(Attendance.lower_bound(date_lower), Attendance.upper_bound(date_upper));
		}
		else if (cmd == "exit")
			return 0;
	}
	return 0;
}
