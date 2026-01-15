/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <fstream>
#include <iomanip>

#define MaxFileNameLength 240
const int alineNum = 16;
using namespace std;
int is_readable_ascii(int ch)
{
	return (ch >= 33 && ch <= 126);
}
void hex_read_file(char* fileName)
{
	ifstream in;
	in.open(fileName, ios::in | ios::binary);
	if (!in) {
		cout << "输入文件" << fileName << "打开失败!" << endl;
		return;
	}
	int aline[alineNum] = {0};
	int lineNum = 0;
	while (true) {
		cout << setfill('0') << setw(8) << hex << lineNum << ": ";
		cout << dec;
		int linei = 0, linech = 0;
		for (; linei < alineNum && (aline[linei] = in.get()) != EOF; linei++) {
			cout << ' ' << hex << uppercase << setiosflags(ios::uppercase) << setfill('0') << setw(2) << aline[linei];
			if (linei == 7)
				cout << " -";
		}
		linech = linei;
		for (; linei < alineNum; linei++){
			cout << "   ";
			if (linei == 7)
				cout << "  ";
		}
		cout << dec << resetiosflags(ios::uppercase);
		cout << "  ";
		for (int i = 0; i < linech; i++) {
			if (is_readable_ascii(aline[i]))
				cout << (char)aline[i];
			else
				cout << '.';
		}
		cout << endl;
		lineNum+= alineNum;
		if (aline[linech] == EOF)
			break;
	}
	in.close();
}

int main()
{
	clog << "文件名以下形式均可以:" << endl;
	clog << "    a.txt                     : 不带路径形式" << endl;
	clog << "    ..\\data\\b.dat             : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	clog << "请输入文件名 : ";
	char fileName[MaxFileNameLength];
	cin >> fileName;
	hex_read_file(fileName);
	return 0;
}
