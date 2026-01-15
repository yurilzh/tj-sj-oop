/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
const int argNum = 3;
class Arg {
public:
	char name[5];
	int valueNum;
	int value;
	int defaultValue;
	int minv, maxv;
	void good(char* v)
	{
		istringstream arg(v);
		int testv;
		arg >> testv;
		if (!arg.fail() && testv >= minv && testv <= maxv)
			value = testv;
		else
			value = defaultValue;
	}
	Arg (const char* name, int valueNum, int defaultValue, int minv = 0, int maxv = 0) 
	{
		strncpy(this->name, name, sizeof(this->name));
		this->valueNum = valueNum;
		this->defaultValue = defaultValue;
		value = defaultValue;
		this->minv = minv;
		this->maxv = maxv;
	}
};
bool ip_isgood(char* ip)
{
	const int maxLength = 15;
	if (strlen(ip) > maxLength)
		return false;
	istringstream ips(ip);
	char test[maxLength + 1];
	for (int i = 0; i < 4; i++) {
		ips.getline(test, maxLength, '.');
		istringstream oneNum(test);
		int ipNum = 0;
		oneNum >> ipNum;
		if (oneNum.fail() || ipNum <= 0 || ipNum >= 255)
			return false;
	}
	return true;
}
int find_arg(const char* arg, Arg* arglist)
{
	int ret = -1;
	for (ret = 0; ret < argNum; ret++)
		if (!strcmp(arg, arglist[ret].name))
			break;
	return ret == argNum ? -1 : ret;
}
void usage(const char* progName)
{
	cout << "Usage: " << progName << " [-l 大小] [-n 数量] [-t] IP地址" << endl;
	cout << "       ==================================" << endl;
	cout << "        参数 附加参数 范围        默认值" << endl;
	cout << "       ==================================" << endl;
	cout << "        -l   1        [32..64000] 64" << endl;
	cout << "        -n   1        [1..1024]   4" << endl;
	cout << "        -t   0        [0..1]      0" << endl;
	cout << "       ==================================" << endl;
}
int main(int argc, char* argv[])
{
	Arg arglist[argNum] = { Arg("-l", 1, 64, 32, 64000),
				        Arg("-n", 1, 4, 1, 1024),
				        Arg("-t", 0, 1)};
	if (argc == 1) {
		usage(argv[0]);
		return 0;
	}
	if (!ip_isgood(argv[argc - 1])) {
		cout << "IP地址错误" << endl;
	}
	else {
		int i;
		for (i = 1; i < argc - 1; i++) {
			if (argv[i][0] != '-') {
				cout << "参数" << argv[i] << "不是以-开头的合法参数" << endl;
				break;
			}
			int a = find_arg(argv[i], arglist);
			if (a == -1) {
				cout << "参数" << argv[i] << "不存在" << endl;
				break;
			}
			if (arglist[a].valueNum == 1) {
				i++;
				if (i == argc - 1 || argv[i][0] == '-') {
					cout << "参数" << arglist[a].name << "没有后续参数" << endl;
					i--;
					break;
				}
				arglist[a].good(argv[i]);
			}
			else if (arglist[a].valueNum == 0)
				arglist[a].value = 1;
		}
		if (i == argc - 1) {
			cout << "参数检查通过" << endl;
			for (int i = 0; i < argNum; i++)
				cout << arglist[i].name << " 参数：" << arglist[i].value << endl;
			cout << "IP地址：" << argv[argc - 1] << endl;
		}
	}
}