/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

const int win_file = 1;
const int linux_file = 2;
const int unknow_file = -1;
const int fail_open = -2;
const int w2lMode = 1;
const int l2wMode = 2;

int check(const char* fileName)
{
	FILE* in = fopen(fileName, "rb");
	if (!in)
		return fail_open;
	int isLinux = 1;
	while (!feof(in)) {
		if (fgetc(in) == 0x0D) {
			char next = 0;
			while ((next = fgetc(in)) == 0x0D && next != EOF)
				;
			if (next == 0x0A)
				isLinux = 0;
		}
		else if (fgetc(in) != 0x0A) {
			if (!isLinux)
				return unknow_file;
		}
	}
	fclose(in);
	return isLinux ? linux_file : win_file;
}
int convert(const char* oriFileName, const char* newFileName, int mode)
{
	if (mode != w2lMode && mode != l2wMode)
		return unknow_file;
	int state = check(oriFileName);
	if (state == fail_open)
		return fail_open;
	else if (state != mode || state == unknow_file)
		return unknow_file;
	FILE* in, *out;
	in = fopen(oriFileName, "rb");
	out = fopen(oriFileName, "wb");
	if (!out)
		return fail_open;
	char current = 0, next = 0;
	int w2lnum = 0, l2wnum = 0;
	next = fgetc(in);
	while (next != EOF && current != EOF) {
		current = next;
		next = fgetc(in);
		if (!(current == 0x0D && next == 0x0A && mode == w2lMode) && !(mode == l2wMode && next == 0x0A))
			fprintf(out, "%c", current);
		else if (mode == l2wMode && next == 0x0A) {
			fprintf(out, "%c\r", current);
			l2wnum++;
		}
		else
			w2lnum++;
	}
	fclose(in);
	fclose(out);
	return mode == w2lMode ? w2lnum : l2wnum;
}
void useage(const char* progName)
{
    printf("Usage : %s --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名\n", progName);
    printf("        %s --check a.txt\n", progName);
    printf("        %s --convert wtol a.win.txt a.linux.txt\n", progName);
    printf("        %s --convert ltow a.linux.txt a.win.txt\n", progName);
    printf("\n");
}

int main(int argc, char* argv[])
{
	int state;
	if (argc == 3 && !strcmp(argv[1], "--check")) {
		state = check(argv[2]);
		if (state == fail_open)
			printf("文件打开失败\n");
		else if (state == unknow_file)
			printf("文件格式无法识别\n");
		else if (state == win_file)
			printf("Windows格式\n");
		else if (state == linux_file)
			printf("Linux格式\n");
	}
	else if (argc == 5 && !strcmp(argv[1], "--convert") && (!strcmp(argv[2], "wtol") || !strcmp(argv[2], "ltow"))) {
		int mode;
		if (!strcmp(argv[2], "wtol"))
			mode = w2lMode;
		else
			mode = l2wMode;
		state = convert(argv[3], argv[4], mode);
		if (state == fail_open)
			printf("文件打开失败\n");
		else if (state == unknow_file)
			printf("文件格式无法识别\n");
		else if (mode == w2lMode)
			printf("转换完成，去除%d个0x0D\n", state);
		else if (mode == l2wMode)
			printf("转换完成，加入%d个0x0D\n", state);
	}
	else
		useage(argv[0]);
	return 0;
}