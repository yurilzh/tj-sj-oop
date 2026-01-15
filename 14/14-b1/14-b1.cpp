/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <iomanip>
#define _ON 1
#define _OFF 0
#define _QUIT 2
using namespace std;
const int SN = 10;
void print_switch(short switchs, const char* prompt = "当前状态：")
{
	cout << prompt << "0x" << hex << setfill('0') << setw(4) << switchs << dec << endl;
	for (int i = 0; i < SN; i++)
		cout << char(i + 'A') << "   ";
	cout << endl;
	for (int i = 0; i < SN; i++) {
		const char* state = (switchs & (1 << i)) ? "ON" : "OFF";
		cout << setfill(' ') << setiosflags(ios::left) << setw(4) << state << resetiosflags(ios::left);
	}
	cout << endl;
}
char my_lower(char ch)
{
	return (ch <= 'Z' && ch >= 'A') ? ch - 'A' + 'a' : ch;
}
int my_strcasecmp(const char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	else {
		int ret;
		const char* p = s1, * q = s2;
		for (; *p && *q;p++, q++) {
			ret = my_lower(*p) - my_lower(*q);
			if (ret)
				break;
		}
		if (!ret)
			ret = *p - *q;
		return ret;
	}
}
void input(int& s, int& operation)
{
	char sw;
	char operat[50];
	char on[] = "ON";
	char off[] = "OFF";
	while (true) {
		cout << "请以(\"A On /J Off\"形式输入，输入\"Q on/off\"退出)" << endl;
		cin >> sw >> operat;
		if (sw == 'q' || sw == 'Q') {
			operation = _QUIT;
			break;
		}
		else if ((sw >= 'a' && sw <= 'a' + SN) || (sw >= 'A' && sw <= 'A' + SN)) {
			s = (sw - 'a' > 0) ? sw - 'a' : sw - 'A';
			if (!my_strcasecmp(operat, on)) {
				operation = _ON;
				break;
			}
			else if (!my_strcasecmp(operat, off)) {
				operation = _OFF;
				break;
			}
		}
	}
}
int main()
{
	short switchs = 0;
	print_switch(switchs, "初始状态：");
	cout << endl;
	while (true) {
		int s, operation;
		input(s, operation);
		if (operation == _OFF)
			switchs &= ~(1 << s);
		else if (operation == _ON)
			switchs |= 1 << s;
		else if (operation == _QUIT)
			break;
		print_switch(switchs);
		cout << endl;
	}
	return 0;
}