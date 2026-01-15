/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
const int Argc = 6;
const char* not7 = "不是7位";
const char* not7num = "不是7位数字";
const char* fileNameError = "文件名超过了32字节";
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int usage(const char* const procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl << endl;
	cout << "e.g. : " << procname << " 2459999 2459998 all       80 screen" << endl;
	cout << "       " << procname << " 2459999 all     14-b1.cpp 75 result.txt" << endl;
	cout << "       " << procname << " all     all     14-b2.cpp 80 check.dat" << endl;
	cout << "       " << procname << " all     all     all       85 screen" << endl;

	return 0;
}
const char* test_id(const char* argv)
{
	if (!strcmp(argv, "all"))
		return NULL;
	else if (strlen(argv) != 7)
		return not7;
	else {
		istringstream testid(argv);
		int test;
		testid >> test;
		if (testid.fail())
			return not7num;
		else
			return NULL;
	}
}
const char* test_file(const char* argv)
{
	if (strlen(argv) > 32)
		return fileNameError;
	else
		return NULL;
}
int criticalValue_test(const char* argv)
{
	int ret, test;
	istringstream arg(argv);
	arg >> test;
	if (!arg.fail() && test >= 60 && test <= 100)
		ret = test;
	else
		ret = 80;
	return ret;
}
int main(int argc, char* argv[])
{
	int criticalValue = 80;
	if (argc != Argc)
		usage(argv[0]);
	else {
		const char* errorprompt = NULL;
		errorprompt = test_id(argv[1]);
		if (errorprompt) {
			cout << "要检查的学号" << errorprompt << endl;
			return 0;
		}
		errorprompt = test_id(argv[2]);
		if (errorprompt) {
			cout << "要匹配的学号" << errorprompt << endl;
			return 0;
		}
		if (!strcmp(argv[1], "all") && strcmp(argv[2], "all")) {
			cout << "检查学号是all，匹配学号必须是all" << endl;
			return 0;
		}
		errorprompt = test_file(argv[3]);
		if (errorprompt) {
			cout << "源程序" << errorprompt << endl;
			return 0;
		}
		criticalValue = criticalValue_test(argv[4]);
		errorprompt = test_file(argv[5]);
		if (errorprompt) {
			cout << "输出结果" << errorprompt << endl;
			return 0;
		}
		cout << "参数检查通过" << endl;
		cout << "检查学号：" << argv[1] << endl;
		cout << "匹配学号：" << argv[2] << endl;
		cout << "源文件名：" << argv[3] << endl;
		cout << "匹配阈值：" << criticalValue << endl;
		cout << "输出目标：" << argv[5] << endl;
	}
}
