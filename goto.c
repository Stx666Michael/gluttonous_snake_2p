#include <stdio.h>
#include "snake.h"

void gotoxy(int x, int y)
{
	COORD point = {x,y};//���Ҫ���õ�λ��x,y
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//ʹ��GetStdHandle(STD_OUTPUT_HANDLE)����ȡ��׼����ľ��
	SetConsoleCursorPosition(HOutput, point);//���ù��λ��
}

void gotoprint0(int x, int y)
{
    gotoxy(x, y);
    printf("��");
}

void gotoprint(int x, int y)
{
    gotoxy(x, y);
    printf("��");
}

void gotoprint2(int x, int y)
{
    gotoxy(x, y);
    printf("��");
}

void gotodelete(int x, int y)
{
    gotoxy(x, y);
    printf("  ");
}
