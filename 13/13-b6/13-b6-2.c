/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//根据需要可加入其它头文件
#ifdef _WIN32
#include <conio.h>
#endif
//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64
const int NameLength = 16;

const int readMode = 1;
const int modifyMode = 2;
const int modifyPromptMode = 3;

#pragma pack(push, 1)
struct PlayerData {
    char a_name[16];
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
   1、所有新增的函数，均不允许定义新的 FILE* 并进行打开/读/写/关闭等操作
   2、上述限制同样适用于main函数
*/

void game_int_short(short* value, const char* name, short max, short min, int i, int mode)
{
    long long llvalue = (long long)(*value);

    if (mode == readMode) {
        if (*value <= max && *value >= min)
            printf("%16s值：%lld\n", name, llvalue);
        else
            printf("非法的%s值：%lld\n", name, llvalue);
    }
    else if (mode == modifyMode) {
        printf("  %c.%-16s(%lld)\n", (char)(i + 'a'), name, llvalue);
    }
    else if (mode == modifyPromptMode) {

        long long inputValue;
        while (1) {
            printf("%s，当前值=%lld，范围[%lld..%lld]，请输入 : ",
                name, llvalue, (long long)min, (long long)max);

            if (scanf("%lld", &inputValue) == 1) {
                if (inputValue <= max && inputValue >= min)
                    break;
                else
                    printf("非法的%s值：%lld\n", name, inputValue);
            }
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        *value = (short)inputValue;
    }
}

void game_int_int(int* value, const char* name, int max, int min, int i, int mode)
{
    long long llvalue = (long long)(*value);

    if (mode == readMode) {
        if (*value <= max && *value >= min)
            printf("%16s值：%lld\n", name, llvalue);
        else
            printf("非法的%s值：%lld\n", name, llvalue);
    }
    else if (mode == modifyMode) {
        printf("  %c.%-16s(%lld)\n", (char)(i + 'a'), name, llvalue);
    }
    else if (mode == modifyPromptMode) {
        long long inputValue;
        while (1) {
            printf("%s，当前值=%lld，范围[%lld..%lld]，请输入 : ",
                name, llvalue, (long long)min, (long long)max);

            if (scanf("%lld", &inputValue) == 1) {
                if (inputValue <= max && inputValue >= min)
                    break;
                else
                    printf("非法的%s值：%lld\n", name, inputValue);
            }
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        *value = (int)inputValue;
    }
}

void game_int_ll(long long* value, const char* name, long long max, long long min, int i, int mode)
{
    long long llvalue = *value;

    if (mode == readMode) {
        if (*value <= max && *value >= min)
            printf("%16s值：%lld\n", name, llvalue);
        else
            printf("非法的%s值：%lld\n", name, llvalue);
    }
    else if (mode == modifyMode) {
        printf("  %c.%-16s(%lld)\n", (char)(i + 'a'), name, llvalue);
    }
    else if (mode == modifyPromptMode) {
        long long inputValue;
        while (1) {
            printf("%s，当前值=%lld，范围[%lld..%lld]，请输入 : ",
                name, llvalue, min, max);

            if (scanf("%lld", &inputValue) == 1) {
                if (inputValue <= max && inputValue >= min)
                    break;
                else
                    printf("非法的%s值：%lld\n", name, inputValue);
            }
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        *value = inputValue;
    }
}

void game_int_char(char* value, const char* name, char max, char min, int i, int mode)
{
    long long llvalue = (long long)(unsigned char)(*value);

    if (mode == readMode) {
        if (*value <= max && *value >= min)
            printf("%16s值：%lld\n", name, llvalue);
        else
            printf("非法的%s值：%lld\n", name, llvalue);
    }
    else if (mode == modifyMode) {
        printf("  %c.%-16s(%lld)\n", (char)(i + 'a'), name, llvalue);
    }
    else if (mode == modifyPromptMode) {

        long long inputValue;
        while (1) {
            printf("%s，当前值=%lld，范围[%lld..%lld]，请输入 : ",
                name, llvalue, (long long)min, (long long)max);

            if (scanf("%lld", &inputValue) == 1) {
                if (inputValue <= max && inputValue >= min)
                    break;
                else
                    printf("非法的%s值：%lld\n", name, inputValue);
            }
            else {
                while (getchar() != '\n')
                    ;
            }
        }
        *value = (char)inputValue;
    }
}


int game_name(char* name, int mode)
{
    int ret = 1;
    int i = 0;

    for (; i < NameLength; i++)
        if (name[i] == '\0')
            break;

    if (i == NameLength && name[i] != '\0')
        ret = 0;

    if (mode == readMode) {
        if (ret)
            printf("%20s%s\n", "玩家昵称：", name);
        else {
            printf("非法的玩家昵称\n");
            return ret;
        }
    }
    else if (mode == modifyMode) {

        printf("  a.%-16s(", "玩家昵称");
        if (ret)
            printf("%s", name);
        else {
            for (int k = 0; k < NameLength; k++)
                putchar(name[k]);
        }
        printf(")\n");
    }
    else if (mode == modifyPromptMode) {
        printf("玩家昵称，当前值=%s，请输入 :", name);

        char inputName[16];
        fgets(inputName, NameLength, stdin);

        inputName[strcspn(inputName, "\n")] = '\0';
        strncpy(name, inputName, NameLength);
    }

    return ret;
}

void switch_term(struct PlayerData* player, int mode, int isModify, char choice)
{
    choice -= 'a';
    if (!isModify || choice == 0) {
        int islegal = game_name(player->a_name, mode);
        if (!islegal && mode == readMode)
            return;
    }
    if (!isModify || choice == 1)
        game_int_short(&player->b, "生命", 10000, 0, 1, mode);
    if (!isModify || choice == 2)
        game_int_short(&player->c, "力量", 10000, 0, 2, mode);
    if (!isModify || choice == 3)
        game_int_short(&player->d, "体质", 8192, 0, 3, mode);
    if (!isModify || choice == 4)
        game_int_short(&player->e, "灵巧", 1024, 0, 4, mode);
    if (!isModify || choice == 5)
        game_int_int(&player->f, "金钱", 100000000, 0, 5, mode);
    if (!isModify || choice == 6)
        game_int_int(&player->g, "名声", 1000000, 0, 6, mode);
    if (!isModify || choice == 7)
        game_int_int(&player->h, "魅力", 1000000, 0, 7, mode);
    if (!isModify || choice == 8)
        game_int_ll(&player->i, "游戏累计时间(us)", 10000000000000000LL, 0LL, 8, mode);
    if (!isModify || choice == 9)
        game_int_char(&player->j, "移动速度", 100, 0, 9, mode);
    if (!isModify || choice == 10)
        game_int_char(&player->k, "攻击速度", 100, 0, 10, mode);
    if (!isModify || choice == 11)
        game_int_char(&player->l, "攻击范围", 100, 0, 11, mode);
    if (!isModify || choice == 12)
        game_int_short(&player->m, "攻击力", 2000, 0, 12, mode);
    if (!isModify || choice == 13)
        game_int_short(&player->n, "防御力", 2000, 0, 13, mode);
    if (!isModify || choice == 14)
        game_int_char(&player->o, "敏捷度", 100, 0, 14, mode);
    if (!isModify || choice == 15)
        game_int_char(&player->p, "智力", 100, 0, 15, mode);
    if (!isModify || choice == 16)
        game_int_char(&player->q, "经验", 100, 0, 16, mode);
    if (!isModify || choice == 17)
        game_int_char(&player->r, "等级", 100, 1, 17, mode);
    if (!isModify || choice == 18)
        game_int_short(&player->s, "魔法", 10000, 0, 18, mode);
    if (!isModify || choice == 19)
        game_int_char(&player->t, "消耗魔法", 100, 0, 19, mode);
    if (!isModify || choice == 20)
        game_int_char(&player->u, "魔法伤害力", 100, 0, 20, mode);
    if (!isModify || choice == 21)
        game_int_char(&player->v, "命中率", 100, 0, 21, mode);
    if (!isModify || choice == 22)
        game_int_char(&player->w, "魔法防御力", 100, 0, 22, mode);
    if (!isModify || choice == 23)
        game_int_char(&player->x, "暴击率", 100, 0, 23, mode);
    if (!isModify || choice == 24)
        game_int_char(&player->y, "耐力", 100, 0, 24, mode);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次fopen、一次fread（因为包含错误处理，允许多次fclose）
***************************************************************************/
int read()
{
    /* 本函数中只允许定义一个 FILE* */
    FILE *fp;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb");

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
    */
    if (!fp) {
        printf("无法打开文件game.dat\n");
        return -1;
    }
    struct PlayerData player;
    fread(&player, sizeof(player), 1, fp);
    fclose(fp);
    switch_term(&player, readMode, 0, 0);
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次fclose）
***************************************************************************/
int modify()
{
    /* 本函数中只允许定义一个 FILE* */
    FILE *fp;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "r+b");

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 fwrite(***, 1, sizeof(demo), fp);
    */
    if (!fp) {
        printf("无法打开文件game.dat\n");
        return -1;
    }
    struct PlayerData player;
    fread(&player, sizeof(player), 1, fp);
    char choice;
    do {
        printf("--------------------------------------\n");
        printf("  游戏存档文件修改工具\n");
        printf("--------------------------------------\n");

        switch_term(&player, modifyMode, 0, 0);

        printf("--------------------------------------\n");
        printf("  0.放弃修改\n");
        printf("  1.存盘退出\n");
        printf("--------------------------------------\n");
        printf("请选择[a..y, 0..1] ");

#ifdef _WIN32
        choice = _getche();
#elif __linux__
        while((choice = getchar()) == '\n')
			;
        getchar();  
#endif
        printf("\n");
		choice = (choice >= 'A' && choice <= 'Z') ? choice + ('a' - 'A') : choice;
        if (choice < 'a' || choice > 'y')
            continue;
        switch_term(&player, modifyPromptMode, 1, choice);
    } while (choice != '1' && choice != '0');

    if (choice == '1') {
        fseek(fp, 0, SEEK_SET);
        fwrite(&player, sizeof(player), 1, fp);
    }
    fclose(fp);
    return 0;
}
void usage(const char* progName)
{
    printf("usage : %s --modify | --read\n", progName);
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
