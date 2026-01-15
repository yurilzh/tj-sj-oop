/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int no;
	char name[17];
	int score;
	int rank;
} student;
 typedef struct {
	student* first;
	int num;
} StudentList;
StudentList creat_list(int num)
{
	StudentList studentList;
	studentList.first = (student*)malloc(num * sizeof(student));  //判断是否成功由main函数负责
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
void sort_id(StudentList list, int begin, int end)
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
		printf("%d %s %d %d\n", list.first[i].no, list.first[i].name, list.first[i].score, list.first[i].rank);
}
void list_input(StudentList list, FILE* in)
{
	for (int i = 0; i < list.num; i++) {
		fscanf(in, "%d %s %d", &list.first[i].no, list.first[i].name, &list.first[i].score);
		list.first[i].rank = 0;
	}
}

int main()
{
	FILE* in = fopen("student.txt", "r");
	if (!in)
		return -1;
	int num;
	fscanf(in, "%d", &num);
	StudentList list = creat_list(num);
	if (list.first == NULL)
		return -1;
	list_input(list, in);
	sort_grade(list);
	cal_grade(list);
	sort_id(list, 0, -1);
	print_list(list);
	free(list.first);
	list.first = NULL;
	list.num = 0;
}