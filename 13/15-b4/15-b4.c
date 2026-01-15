/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxFileNameLength 240
#define alineLength 50
#define alineNum 16
int hex2dec(int ch, int ch2)
{
	return 16 * (ch - 'A' >= 0 ? ch - 'A' + 10 : ch - '0') + (ch2 - 'A' >= 0 ? ch2 - 'A' + 10 : ch2 - '0');
}
void hex2ori(char* ofileName, char* fileName)
{
	FILE* in, *out;
	in = fopen(ofileName, "r");
	if (!in) {
		printf("输入文件%s打开失败!\n", fileName);
		return;
	}
	out = fopen(fileName, "wb");
	while (1) {
		int tail = 0;
		while ((tail = fgetc(in)) != ' ' && tail != EOF)
			;
		if (tail == EOF)
			break;
		for (int i = 0; i < alineLength; i++) {
			int ch = fgetc(in);
			if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')) {
				int ch2 = fgetc(in);
				i++;
				fprintf(out, "%c", (char)hex2dec(ch, ch2));
			}
		}
		while (fgetc(in) != '\n')
			;
	}
	fclose(in);
	fclose(out);
}
int main()
{	
	fprintf(stderr, "文件名以下形式均可以:\n");
	fprintf(stderr,"    a.txt                     : 不带路径形式\n");
	fprintf(stderr,"    ..\\data\\b.dat             : 相对路径形式\n");
	fprintf(stderr,"    C:\\Windows\\System32\\c.dat : 绝对相对路径形式\n");
	fprintf(stderr,"请输入要转换的hex格式文件名 : ");
	char ofileName[MaxFileNameLength];
	scanf("%s", ofileName);
	fprintf(stderr,"请输入转换后的文件名        : ");
	char fileName[MaxFileNameLength];
	scanf("%s", fileName);
	hex2ori(ofileName, fileName);
	return 0;
}
