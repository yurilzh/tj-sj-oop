/* 2451899 ¡ı’‹∫¿ º∆ø∆ */
#include <iostream>
#include <fstream>
using namespace std;

struct student {
	int no;
	char name[17];
	int score;
	struct student* next;
};
typedef struct student Student;
typedef struct {
	student* first;
	student* last;
} StudentList;

StudentList input()
{
	StudentList list = {NULL, NULL};
	ifstream in;
	in.open("list.txt", ios::in);
	while (true) {
		int id;
		in >> id;
		if (id == 9999999)
			break;
		student* p = new(nothrow) student;
		if (!p)
			return {NULL, NULL};
		p->no = id;
		in >> p->name >> p->score;
		p->next = NULL;
		if (list.first) {
			list.last->next = p;
			list.last = p;
		}
		else {
			list.first = p;
			list.last = p;
		}
	}
	return list;
}
void print_list(StudentList list)
{
	for (student* p = list.first; p; p = p->next) {
		cout << p->no << ' ' << p->name << ' ' << p->score << endl;
	}
}
void free_list(StudentList list)
{
	for (student* p = list.first, *q = list.first->next; p; p = q) {
		q = p->next;
		delete p;
		p = NULL;
	}
}
int main()
{
	StudentList list = input();
	if (list.first == NULL)
		return -1;
	print_list(list);
	free_list(list);
}