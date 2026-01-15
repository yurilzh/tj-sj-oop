/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <fstream>
#include <iomanip>

#define MaxFileNameLength 240
#define alineLength 50
const int alineNum = 16;
using namespace std;
int hex2dec(int ch, int ch2)
{
	return 16 * (ch - 'A' >= 0 ? ch - 'A' + 10 : ch - '0') + (ch2 - 'A' >= 0 ? ch2 - 'A' + 10 : ch2 - '0');
}
void hex2ori(char* ofileName, char* fileName)
{
	ifstream in;
	in.open(ofileName, ios::in);
	if (!in) {
		cout << "输入文件" << fileName << "打开失败!" << endl;
		return;
	}
	ofstream out;
	out.open(fileName, ios::out | ios::binary);
	while (true) {
		int tail = 0;
		while ((tail = in.get()) != ' ' && tail != EOF)
			;
		if (tail == EOF)
			break;
		for (int i = 0; i < alineLength; i++) {
			int ch = in.get();
			if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')) {
				int ch2 = in.get();
				i++;
				out << (char)hex2dec(ch, ch2);
			}
		}
		while (in.get() != '\n')
			;
	}
	in.close();
	out.close();
}
int main()
{
	clog << "文件名以下形式均可以:" << endl;
	clog << "    a.txt                     : 不带路径形式" << endl;
	clog << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	clog << "请输入要转换的hex格式文件名 : ";
	char ofileName[MaxFileNameLength];
	cin >> ofileName;
	clog << "请输入转换后的文件名        : ";
	char fileName[MaxFileNameLength];
	cin >> fileName;
	hex2ori(ofileName, fileName);
	return 0;
}
