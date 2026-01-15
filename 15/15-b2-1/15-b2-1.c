/* 2451899 ¡ı’‹∫¿ º∆ø∆ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	int no;
	char name[17];
	int score;
	struct student* next;
};
typedef struct student Student;
typedef struct {
	Student* first;
	Student* last;
} StudentList;

StudentList input()
{
	StudentList list = {NULL, NULL};
	FILE* in = fopen("list.txt", "r");
	if (!in)
		return list;
	while (1) {
		int id;
		fscanf(in, "%d", &id);
		if (id == 9999999)
			break;
		Student* p = (Student*)malloc(sizeof(Student));
		if (!p) {
			list.first = list.last = NULL;
			break;
		}
		p->no = id;
		fscanf(in, "%s %d", p->name, &(p->score));
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
	for (Student* p = list.first; p; p = p->next) {
		printf("%d %s %d\n", p->no, p->name, p->score);
	}
}
void free_list(StudentList list)
{
	for (Student* p = list.first, *q = list.first->next; p; p = q) {
		q = p->next;
		free(p);
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