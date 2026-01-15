/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxFileNameLength 240
#define alineNum 16
int is_readable_ascii(int ch)
{
	return (ch >= 33 && ch <= 126);
}
void hex_read_file(char* fileName)
{
	FILE* in;
	in = fopen(fileName, "rb");
	if (in == NULL) {
		printf("输入文件%s打开失败!\n", fileName);
		return;
	}
	int aline[alineNum] = {0};
	int lineNum = 0;
    while (1) {
        printf("%08X: ", lineNum);                      
        /* cout << dec; */                             

        int linei = 0, linech = 0;
        for (; linei < alineNum && (aline[linei] = fgetc(in)) != EOF; linei++) {
            printf(" %02X", aline[linei]);            
            if (linei == 7)
                printf(" -");                        
        }

        linech = linei;
        for (; linei < alineNum; linei++) {
            printf("   ");                          
            if (linei == 7)
                printf("  ");                      
        }

        printf("  ");  

        for (int i = 0; i < linech; i++) {
            if (is_readable_ascii(aline[i]))
                printf("%c", aline[i]);
            else
                printf(".");          
        }

        printf("\n");                
        lineNum += alineNum;        
        if (aline[linech] == EOF)  
            break;                
    }
	fclose(in);
}

int main()
{
	fprintf(stderr, "文件名以下形式均可以:\n");
	fprintf(stderr, "    a.txt                     : 不带路径形式\n");
	fprintf(stderr, "    ..\\data\\b.dat             : 相对路径形式\n");
	fprintf(stderr, "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式\n");
	fprintf(stderr, "请输入文件名 : ");
	char fileName[MaxFileNameLength];
    scanf("%s", fileName);
	hex_read_file(fileName);
	return 0;
}

