/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <fstream>
using namespace std;

struct student {
	int no;
	char name[17];
	int score;
	int rank;
};
struct StudentList {
	student* first;
	int num;
};
StudentList creat_list(int num)
{
	StudentList studentList;
	studentList.first = new(nothrow) student[num];    //判断是否成功由main函数负责
	studentList.num = num;
	return studentList;
}
void cal_grade(StudentList list)
{
	for (int stuNum = 0; stuNum < list.num; stuNum++) {
		int agrade = list.first[stuNum].score;
		int arank = stuNum + 1;
		while (stuNum < list.num && list.first[stuNum].score == agrade) {
			list.first[stuNum].rank = arank;
			stuNum++;
		}
		if (stuNum < list.num && list.first[stuNum].score != agrade)
			stuNum--;
	}
}
void sort_grade(StudentList list)
{
	for (int i = 0; i < list.num; i++) {
		int maxi = 0, currentMax = -1;
		for (int j = i; j < list.num; j++) {
			if (list.first[j].score > currentMax) {
				maxi = j;
				currentMax = list.first[j].score;
			}
		}
		student tmp = list.first[i];
		list.first[i] = list.first[maxi];
		list.first[maxi] = tmp;
	}
}
void sort_id(StudentList list, int begin = 0, int end = -1)
{
	if (end == -1 || end > list.num)
		end = list.num;
	for (int i = begin; i < end; i++) {
		int mini = i, currentMinId = list.first[i].no;
		for (int j = i; j < list.num; j++) {
			if (list.first[j].no < currentMinId) {
				mini = j;
				currentMinId = list.first[j].no;
			}
		}
		student tmp = list.first[i];
		list.first[i] = list.first[mini];
		list.first[mini] = tmp;
	}
}
void print_list(const StudentList list)
{
	for (int i = 0; i < list.num; i++)
		cout << list.first[i].no << ' ' << list.first[i].name << ' ' << list.first[i].score << ' ' << list.first[i].rank << endl;
}
void input(StudentList list, ifstream& in)
{
	for (int i = 0; i < list.num; i++) {
		in >> list.first[i].no >> list.first[i].name >> list.first[i].score;
		list.first[i].rank = 0;
	}
}

int main()
{
	ifstream in;
	in.open("student.txt", ios::in);
	int num;
	in >> num;
	StudentList list = creat_list(num);
	if (list.first == NULL)   //判断是否成功申请
		return -1;
	input(list, in);
	sort_grade(list);
	cal_grade(list);
	sort_id(list);
	print_list(list);
	delete[] list.first;
	list.first = NULL;
	list.num = 0;
}