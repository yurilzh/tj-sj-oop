/* 2451899 刘哲豪 计科 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int win_file = 1;
const int linux_file = 2;
const int unknow_file = -1;
const int fail_open = -2;
const int w2lMode = win_file;
const int l2wMode = linux_file;

int check(const char* fileName)
{
	ifstream in;
	in.open(fileName, ios::in | ios::binary);
	if (!in)
		return fail_open;
	int isLinux = 1;
	while (!in.eof()) {
		if (in.get() == 0x0D) {
			char next = 0;
			while (!in.eof() && (next = in.get()) == 0x0D)
				;
			if (next == 0x0A)
				isLinux = 0;
		}
		else if (in.get() == 0x0A) {
			if (!isLinux)
				return unknow_file;
		}
	}
	in.close();
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
	ifstream in;
	in.open(oriFileName, ios::in | ios::binary);
	ofstream out;
	out.open(newFileName, ios::out | ios::binary);
	if (!out)
		return fail_open;
	char current = 0, next = 0;
	int w2lnum = 0, l2wnum = 0;
	next = in.get();
	while (next != EOF && current != EOF) {
		current = next;
		next = in.get();
		if (!(current == 0x0D && next == 0x0A && mode == w2lMode) && !(mode == l2wMode && next == 0x0A))
			out << current;
		else if (mode == l2wMode && next == 0x0A) {
			out << current << (char)0x0D;
			l2wnum++;
		}
		else
			w2lnum++;
	}
	in.close();
	out.close();
	return mode == w2lMode ? w2lnum : l2wnum;
}
void useage(const char* progName)
{
	cout << "Usage : " << progName << " --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名" << endl;
	cout << "        " << progName << " --check a.txt" << endl;
	cout << "        " << progName << " --convert wtol a.win.txt a.linux.txt" << endl;
	cout << "        " << progName << " --convert ltow a.linux.txt a.win.txt" << endl;
	cout << endl;
}
int main(int argc, char *argv[])
{
	int state;
	if (argc == 3 && !strcmp(argv[1], "--check")) {
		state = check(argv[2]);
		if (state == fail_open)
			cout << "文件打开失败" << endl;
		else if (state == unknow_file)
			cout << "文件格式无法识别" << endl;
		else if (state == win_file)
			cout << "Windows格式" << endl;
		else if (state == linux_file)
			cout << "Linux格式" << endl;
	}
	else if (argc == 5 && !strcmp(argv[1], "--convert") && (!strcmp(argv[2], "wtol") || !strcmp(argv[2], "ltow"))) {
		int mode;
		if (!strcmp(argv[2], "wtol"))
			mode = w2lMode;
		else
			mode = l2wMode;
		state = convert(argv[3], argv[4], mode);
		if (state == fail_open)
			cout << "文件打开失败" << endl;
		else if (state == unknow_file)
			cout << "文件格式无法识别" << endl;
		else if (mode == w2lMode)
			cout << "转换完成，去除" << state << "个0x0D" << endl;
		else if(mode == l2wMode)
			cout << "转换完成，加入" << state << "个0x0D" << endl;
	}
	else
		useage(argv[0]);
	return 0;
}
