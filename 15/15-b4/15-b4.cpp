/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
using namespace std;

struct student {
	unsigned int no;
	char* name;
	char* school;
	bool isSelect;
};
class StudentList {
public:
	student* first;
	int length;
};

StudentList input(ifstream& in)
{
	StudentList list = { NULL, 0 };
	in >> list.length;
	list.first = new(nothrow) student[list.length];
	if (!list.first)
		return list;
	for(int i = 0; i < list.length; i++){
		student* p = list.first + i;
		in >> p->no;
		char mname[20];
		char mschool[10];
		in >> mname >> mschool;
		p->name = new(nothrow) char[strlen(mname) + 1];
		if (!p->name)
			return { NULL, 0 };
		p->school = new(nothrow) char[strlen(mschool) + 1];
		if (!p->school)
			return { NULL, 0 };
		strncpy(p->name, mname, strlen(mname) + 1);
		strncpy(p->school, mschool, strlen(mschool) + 1);
		p->isSelect = false;
	}
	return list;
}
void print_select_list(StudentList list, int selectNum)
{
	srand((unsigned int)time(0));
	ofstream out;
	out.open("result.txt", ios::out);
	int i = 0;
	while (i < selectNum) {
		int selectStu = rand() % list.length;
		student* p = list.first + selectStu;
		if (!p->isSelect) {
			p->isSelect = true;
			i++;
			out << p->no << ' ' << p->name << ' ' << p->school << endl;
		}
	}
}
void print_all(StudentList list)
{
	for (student* p = list.first; p < list.first + list.length; p++) {
		cout << p->no << ' ' << p->name << p->school << endl;
	}
}
int main()
{
	ifstream in;
	in.open("stulist.txt", ios::in);
	if (!in)
		return -1;
	int selectNum;
	in >> selectNum;
	StudentList ori = input(in);
	if (!ori.first)
		return -1;
	cout << "读取成功" << endl;
	print_select_list(ori, selectNum);
	cout << "抽取成功" << endl;
	free(ori.first);
	ori.first = NULL;
	ori.length = 0;
}
/*
采用申请连续空间的方式，但是名字和学校进行二次申请
因为需要进行大量的随机访问，使用链表较慢。
名字和学校的长短不一，进行二次申请以避免浪费空间
*/
