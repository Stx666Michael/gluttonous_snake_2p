#include <stdio.h>
#include "snake.h"

char name[20];

int main(void)
{
	welcome();
	creatgraph();
	creatfood();
	creatfood2();
	if (ClickControl() == 0) return 0;
	return 0;
}

int ClickControl()
{
	while(1)
	{
		if (Judge() == 0) return 0;
		if (kbhit())
		{
			click = click2 = getch();
			if (click != put && click != 'i' && click != 'k' && click != 'j' && click != 'l' && click != 'o')
				click_ = click;
			else if (click == put)
			{
				drop();
				click = click_;
			}
			else
				click = click_;
			
			if (click2 != put2 && click2 != 'w' && click2 != 's' && click2 != 'a' && click2 != 'd' && click2 != 'e')
				click2_ = click2;
			else if (click2 == put2)
			{
				drop2();
				click2 = click2_;
			}
			else
				click2 = click2_;				
		}           
        MovingBody();
        Eating();
        MovingBody2();
        Eating2();
        CursorInvisible();
	}
	return 1;
}

void welcome()
{
    gotoxy(20, 10);
    printf("WELCOME TO THE GAME OF RETRO SNAKE 2");
    gotoxy(20, 13);
    printf("请在英文输入法中操作，反向移动及其他按键将会暂停");
	gotoxy(20, 15);
	printf("Snake 1: WASD控制方向，E拉黑; Snake 2: IJKL控制方向，O拉黑");
    gotoxy(20, 18);
    printf("PLEASE ENTER YOUR NAME: ");
    scanf("%s", &name);
    system("cls");
}

void CursorInvisible()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}

int Judge()
{
	if (head->x == leftside || head->x == rightside || head->y == top || head->y == bottom)
	{
		Finish();
		return 0;
	}
	if (head2->x == leftside || head2->x == rightside || head2->y == top || head2->y == bottom)
	{
		Finish2();
		return 0;
	}
	snake* p = head->next;
	snake* P = head2->next;
	snake* w = waste->next;
	snake* W = waste2->next;
	while (p != NULL)
	{
		if (head->x == p->x && head->y == p->y)
		{
			Finish();
			return 0;
		}
		/*else if (head2->x == p->x && head2->y == p->y)
		{
			Finish2();
			return 0;
		}*/
		p = p->next;
	}
	while (P != NULL)
	{
		if (head2->x == P->x && head2->y == P->y)
		{
			Finish2();
			return 0;
		}
		/*else if (head->x == P->x && head->y == P->y)
		{
			Finish();
			return 0;
		}*/
		P = P->next;
	}
	while (w != NULL)
	{
		if (head2->x == w->x && head2->y == w->y)
		{
			Finish2();
			return 0;
		}
		w = w->next;
	}
	while (W != NULL)
	{
		if (head->x == W->x && head->y == W->y)
		{
			Finish();
			return 0;
		}
		W = W->next;
	}
	return 1;
}

void Finish()
{
	system("cls");
	snake* p = head, * q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	snake* P = head2, * Q;
	while (P != NULL)
	{
		Q = P->next;
		free(P);
		P = Q;
	}
	snake* r = waste, * s;
	while (r != NULL)
	{
		s = r->next;
		free(r);
		r = s;
	}
	snake* R = waste2, * S;
	while (R != NULL)
	{
		S = R->next;
		free(R);
		R = S;
	}
	printf("Snake 2 wins!\n\n");
	system("pause");
}

void Finish2()
{
	system("cls");
	snake* p = head, * q;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	snake* P = head2, * Q;
	while (P != NULL)
	{
		Q = P->next;
		free(P);
		P = Q;
	}
	snake* r = waste, * s;
	while (r != NULL)
	{
		s = r->next;
		free(r);
		r = s;
	}
	snake* R = waste2, * S;
	while (R != NULL)
	{
		S = R->next;
		free(R);
		R = S;
	}
	printf("Snake 1 wins!\n\n");
	system("pause");
}
