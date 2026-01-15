/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#ifdef _WIN32
#include <conio.h>
#endif
//根据需要可加入其它头文件
using namespace std;

const int NameLength = 16;

const int readMode = 1;
const int modifyMode = 2;
const int modifyPromptMode = 3;
//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64
#pragma pack(push, 1)
struct PlayerData {
    char a_name[NameLength];
    short b;
    short c;
    short d;
    short e;
    int f;
    int g;
    int h;
    long long i;
    char j;
    char k;
    char l;
    char useless;
    short m;
    short n;
    char o;
    char p;
    char q;
    char r;
    short s;
    char t;
    char u;
    char v;
    char w;
    char x;
    char y;
};
#pragma pack(pop)

/* 此处允许新增函数，数量不限
   1、所有新增的函数，均不允许定义新的 fstream / ifstream / ofstream 流对象，并进行打开/读/写/关闭等操作
   2、所有新增的函数，均不允许用C方式进行文件处理
   3、上述两个限制同样适用于main函数
*/
template<typename T>
static void game_int(T& value, const char* name, const T max, const T min, int i, int mode)
{
    long long llvalue = (long long)value;
    if (mode == readMode) {
        if (value <= max && value >= min)
            cout << setw(16) << name << "值：" << llvalue << endl;
        else
            cout << "非法的" << name << "值：" << llvalue << endl;
    }
    else if (mode == modifyMode)
        cout << "  " << (char)(i + 'a') << "." << left << setw(16) << name << "(" << llvalue << ")" << endl;
    else if (mode == modifyPromptMode) {
        long long inputValue;
        while (true) {
            cout << name << "，当前值=" << llvalue << "，范围[" <<(long long) min << ".." <<(long long) max << "]，请输入 : ";
            cin >> inputValue;
            if (cin.good()) {
                if (inputValue <= max && inputValue >= min)
                    break;
                else
                    cout << "非法的" << name << "值：" << inputValue << endl;
            }
            else {
                cin.clear();
                cin.ignore(1024, '\n');
            }
        }
        value = (T)inputValue;
    }
}
static bool game_name(char* name, int mode) 
{ 
    bool ret = true;
    int i = 0;
    for (; i < NameLength; i++)
		if (name[i] == '\0')
			break;
    if (i == NameLength && name[i] != '\0')
        ret = false;
    if (mode == readMode) {
        if (ret)
            cout << setw(20) << "玩家昵称：" << name << endl;
        else {
            cout << "非法的玩家昵称" << endl;
            return ret;
        }
    }
    else if (mode == modifyMode) {
        cout << "  a." << left << setw(16) << "玩家昵称" << "(";
        if (ret)
            cout << name;
        else {
            for (int i = 0; i < NameLength; i++)
                putchar(name[i]);
        }
        cout << ")" << endl;
    }
    else if (mode == modifyPromptMode) {
        cout << "玩家昵称，当前值=" << name << "，请输入 :";
        char inputName[NameLength];
        cin.getline(inputName, NameLength, '\n');
        strncpy(name, inputName, NameLength);
    }
    return ret;
}
void switch_term(PlayerData& player, int mode, int isModeify, char choice = 0)
{
    choice = choice - 'a';
    if (!isModeify || choice == 0) {
        bool islegal = game_name(player.a_name, mode);
        if (!islegal && mode == readMode)
            return;
    }
    if(!isModeify || choice == 1)
		game_int(player.b, "生命", short(10000), short(0), 1, mode);
    if(!isModeify || choice == 2)
		game_int(player.c, "力量", short(10000), short(0), 2, mode);
	if (!isModeify || choice == 3)
		game_int(player.d, "体质", short(8192), short(0), 3, mode);
	if (!isModeify || choice == 4)
		game_int(player.e, "灵巧", short(1024), short(0), 4, mode);
	if (!isModeify || choice == 5)
		game_int(player.f, "金钱", int(100000000), int(0), 5, mode);
	if (!isModeify || choice == 6)
		game_int(player.g, "名声", int(1000000), int(0), 6, mode);
	if (!isModeify || choice == 7)
		game_int(player.h, "魅力", int(1000000), int(0), 7, mode);
	if (!isModeify || choice == 8)
		game_int(player.i, "游戏累计时间(us)", (long long)(10000000000000000), (long long)(0), 8, mode);
	if (!isModeify || choice == 9)
		game_int(player.j, "移动速度", char(100), char(0), 9, mode);
	if (!isModeify || choice == 10)
		game_int(player.k, "攻击速度", char(100), char(0), 10, mode);
	if (!isModeify || choice == 11)
		game_int(player.l, "攻击范围", char(100), char(0), 11, mode);
	if (!isModeify || choice == 12)
		game_int(player.m, "攻击力", short(2000), short(0), 12, mode);
	if (!isModeify || choice == 13)
		game_int(player.n, "防御力", short(2000), short(0), 13, mode);
	if (!isModeify || choice == 14)
		game_int(player.o, "敏捷度", char(100), char(0), 14, mode);
	if (!isModeify || choice == 15)
		game_int(player.p, "智力", char(100), char(0), 15, mode);
	if (!isModeify || choice == 16)
		game_int(player.q, "经验", char(100), char(0), 16, mode);
	if (!isModeify || choice == 17)
		game_int(player.r, "等级", char(100), char(1), 17, mode);
	if (!isModeify || choice == 18)
		game_int(player.s, "魔法", short(10000), short(0), 18, mode);
	if (!isModeify || choice == 19)
		game_int(player.t, "消耗魔法", char(100), char(0), 19, mode);
	if (!isModeify || choice == 20)
		game_int(player.u, "魔法伤害力", char(100), char(0), 20, mode);
	if (!isModeify || choice == 21)
		game_int(player.v, "命中率", char(100), char(0), 21, mode);
	if (!isModeify || choice == 22)
		game_int(player.w, "魔法防御力", char(100), char(0), 22, mode);
	if (!isModeify || choice == 23)
		game_int(player.x, "暴击率", char(100), char(0), 23, mode);
	if (!isModeify || choice == 24)
		game_int(player.y, "耐力", char(100), char(0), 24, mode);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read（因为包含错误处理，允许多次close）
***************************************************************************/
int read()
{
    /* 本函数中只允许定义一个 ifstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    ifstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::in | ios::binary);

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
    */
    if (!gfile) {
        cout << "无法打开文件game.dat" << endl;
        return -1;
    }
    struct PlayerData player;
    gfile.read((char*)(&player), sizeof(player));
    switch_term(player, readMode, 0);
    gfile.close();
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次close）
***************************************************************************/
int modify()
{
    /* 本函数中只允许定义一个 fstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    fstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::in | ios::binary | ios::out);

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 gfile.write(***, sizeof(demo));
    */
    if (!gfile) {
        cout << "无法打开文件game.dat" << endl;
        return -1;
    }
    struct PlayerData player;
	gfile.read((char*)(&player), sizeof(player));
    char choice;
    do {
        cout << "--------------------------------------" << endl;
        cout << "  游戏存档文件修改工具" << endl;
        cout << "--------------------------------------" << endl;
        switch_term(player, modifyMode, 0);
        cout << "--------------------------------------" << endl;
        cout << "  0.放弃修改" << endl;
        cout << "  1.存盘退出" << endl;
        cout << "--------------------------------------" << endl;
        cout << "请选择[a..y, 0..1] ";
#ifdef _WIN32
        choice = _getche();
#elif __linux__
        while((choice = getchar()) == '\n')
			;
        getchar();
#endif
        cout << endl;
		choice = (choice >= 'A' && choice <= 'Z') ? choice + ('a' - 'A') : choice;
        if (choice < 'a' || choice > 'y')
            continue;
        switch_term(player, modifyPromptMode, 1, choice);
    } while (choice != '1' && choice != '0');
    if (choice == '1') {
        if (!gfile.good())
            gfile.clear();
        gfile.seekp(0, ios::beg);
		gfile.write((char*)(&player), sizeof(player));
    }
    gfile.close();
    return 0;
}

void usage(const char* progName)
{
    cout << "usage : " << progName << " --modify | --read" << endl;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数允许带参数，不允许进行文件读写
***************************************************************************/
int main(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "--read"))
        read();
    else if(argc == 2 && !strcmp(argv[1], "--modify"))
        modify();
    else
        usage(argv[0]);
    return 0;
}
