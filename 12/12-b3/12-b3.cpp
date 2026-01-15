/* 2451899 刘哲豪 计科 */
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入月份(1-12)" << endl;
    const char* month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int mon;
	cin >> mon;
	if (cin.good() && mon <= 12 && mon >= 1)
		cout << month[mon - 1] << endl;
	else
		cout << "Invalid" << endl;
	//除已有6行外，填入语句行数不超过8行（不含注释）
	return 0;
}