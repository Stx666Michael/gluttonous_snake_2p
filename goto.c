#include <stdio.h>
#include "snake.h"

void gotoxy(int x, int y)
{
	COORD point = {x,y};//光标要设置的位置x,y
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
	SetConsoleCursorPosition(HOutput, point);//设置光标位置
}

void gotoprint0(int x, int y)
{
    gotoxy(x, y);
    printf("●");
}

void gotoprint(int x, int y)
{
    gotoxy(x, y);
    printf("■");
}

void gotoprint2(int x, int y)
{
    gotoxy(x, y);
    printf("◆");
}

void gotodelete(int x, int y)
{
    gotoxy(x, y);
    printf("  ");
}
