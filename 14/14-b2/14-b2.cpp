/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
/* 如果有需要，此处可以添加头文件 */

using namespace std;
/* 允许定义常变量/宏定义，但不允许定义全局变量 */
#ifdef _WIN32
const char flower[] = { 'c', 'd', 'h', 's' };
#endif
#ifdef __linux__
const char flower[] = { 'C', 'D', 'H', 'S' };
#endif
const char number[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

/* 可以添加自己需要的函数 */

/***************************************************************************
  函数名称：
  功    能：打印某个玩家的牌面信息，如果是地主，后面加标记
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int print(const char *prompt, const bool landlord, const unsigned long long player)
{
	/* 只允许定义不超过三个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	cout << prompt;
	unsigned long long Player = player;
	for (int i = 0; Player; Player >>= 1, i++) {
		if (Player & 1) {
			if (i < 52) {
				cout << flower[i % 4] << number[i / 4];
				cout << ' ';
			}
			else if (i == 52)
				cout << "RJ ";
			else if (i == 53)
				cout << "BJ ";
		}
	}
	if (landlord)
		cout << "(地主)";
	cout << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：发牌（含键盘输入地主）
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int deal(unsigned long long *player)
{
	/* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	srand((unsigned int)time(0));
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 3; j++) {
			while (true) {
				int pos = rand() % 54;
				if ((player[0] & (1llu << pos)) || (player[1] & (1llu << pos)) || (player[2] & (1llu << pos)))
					continue;
				player[j] |= (1llu << pos);
				break;
			}
		}
		cout << "第" << i + 1 << "轮结束：" << endl;
		print("甲的牌：", 0, player[0]);
		print("乙的牌：", 0, player[1]);
		print("丙的牌：", 0, player[2]);
	}
	cout << endl;
	cout << "请选择一个地主[0-2]：" << endl;
	int landload;
	cin >> landload;
	const unsigned long long b54 = 0x003FFFFFFFFFFFFF;
	player[landload] |= (b54 & ~(player[0] | player[1] | player[2]));
	return landload; //此处修改为选定的地主(0-2)
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数，不准修改
 ***************************************************************************/
int main()
{
	unsigned long long player[3] = { 0 }; //存放三个玩家的发牌信息
	int landlord; //返回0-2表示哪个玩家是地主

	cout << "按回车键开始发牌";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("甲的牌：", (landlord == 0), player[0]);
	print("乙的牌：", (landlord == 1), player[1]);
	print("丙的牌：", (landlord == 2), player[2]);

	return 0;
}
