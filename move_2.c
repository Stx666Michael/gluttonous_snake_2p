#include <stdio.h>
#include "snake.h"

int sleeptime2 = 50;

void MovingBody2()
{
	int x = head2->x, y = head2->y;
	snake* p = head2;
	while (p->next != NULL)
		p = p->next;
	gotodelete(p->x, p->y);
	switch(click2)
	{
		case up2:
			if (_click2 != down2)
			{
				y -= 1;
				_click2 = up2;
			}			
			break;			
		case down2:
			if (_click2 != up2)
			{
				y += 1;
				_click2 = down2;
			}
			break;
		case left2:
			if (_click2 != right2)
			{
				x -= 2;
				_click2 = left2;
			}
			break;
		case right2:
			if (_click2 != left2)
			{
				x += 2;
				_click2 = right2;
			}
			break;
		default:
			break;
	}
	if (x != head2->x || y != head2->y)
		ChangeBody2(x,y);
	p = head2;
	gotoprint2(p->x, p->y);
	Sleep(sleeptime2);
}

void ChangeBody2(int x, int y)
{
	snake* p = head2;
	while (p->next->next != NULL)
		p = p->next;
	free(p->next);
	p->next = NULL;
	snake* new_head = (snake*)malloc(sizeof(snake));
	new_head->x = x;
	new_head->y = y;
	new_head->next = head2;
	head2 = new_head;
}

void Eating2()
{
	if (head2->x == food.x && head2->y == food.y)
	{
		creatfood();
		grow2();
	}
	if (head2->x == food2.x && head2->y == food2.y)
	{
		creatfood2();
		grow2();
	}
	snake* w = waste2;
	while (w->next != NULL)
	{
		if (head2->x == w->next->x && head2->y == w->next->y)
		{
			grow2();
			if (w->next->next != NULL)
			{
				snake*v = w->next->next;
				free(w->next);
				w->next = v;			
			}
			else
			{
				free(w->next);
				w->next = NULL;
			}	
		}
		else
			w = w->next;
	}
}

void drop2()
{
	snake* p = head2;
	if (p->next->next->next != NULL)
	{
		while (p->next->next != NULL)
			p = p->next;
		int x = p->next->x, y = p->next->y;
		gotodelete(p->next->x, p->next->y);
		free(p->next);
		p->next = NULL;
		snake* new_waste = (snake*)malloc(sizeof(snake));
		snake* w = waste2;
		while (w->next != NULL)
			w = w->next;
		w->next = new_waste;
		new_waste->next = NULL;
		new_waste->x = x;
		new_waste->y = y;
		gotoprint2(x,y);
	}
}

void grow2()
{
	snake* new_body = (snake*)malloc(sizeof(snake));
	snake* p = head2;
	while (p->next != NULL)
		p = p->next;
	p->next = new_body;
	new_body->next = NULL;
}
