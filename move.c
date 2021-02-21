#include <stdio.h>
#include "snake.h"

int sleeptime = 50;

void MovingBody()
{
	int x = head->x, y = head->y;
	snake* p = head;
	while (p->next != NULL)
		p = p->next;
	gotodelete(p->x, p->y);
	switch(click)
	{
		case up:
			if (_click != down)
			{
				y -= 1;
				_click = up;
			}			
			break;			
		case down:
			if (_click != up)
			{
				y += 1;
				_click = down;
			}
			break;
		case left:
			if (_click != right)
			{
				x -= 2;
				_click = left;
			}
			break;
		case right:
			if (_click != left)
			{
				x += 2;
				_click = right;
			}
			break;
		default:
			break;
	}
	if (x != head->x || y != head->y)
		ChangeBody(x,y);
	p = head;
	gotoprint(p->x, p->y);
	Sleep(sleeptime);
}

void ChangeBody(int x, int y)
{
	snake* p = head;
	while (p->next->next != NULL)
		p = p->next;
	free(p->next);
	p->next = NULL;
	snake* new_head = (snake*)malloc(sizeof(snake));
	new_head->x = x;
	new_head->y = y;
	new_head->next = head;
	head = new_head;
}

void Eating()
{
	if (head->x == food.x && head->y == food.y)
	{
		creatfood();
		grow();
	}
	if (head->x == food2.x && head->y == food2.y)
	{
		creatfood2();
		grow();
	}
	snake* w = waste;
	while (w->next != NULL)
	{
		if (head->x == w->next->x && head->y == w->next->y)
		{
			grow();
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

void drop()
{
	snake* p = head;
	if (p->next->next->next != NULL)
	{
		while (p->next->next != NULL)
			p = p->next;
		int x = p->next->x, y = p->next->y;
		gotodelete(p->next->x, p->next->y);
		free(p->next);
		p->next = NULL;
		snake* new_waste = (snake*)malloc(sizeof(snake));
		snake* w = waste;
		while (w->next != NULL)
			w = w->next;
		w->next = new_waste;
		new_waste->next = NULL;
		new_waste->x = x;
		new_waste->y = y;
		gotoprint(x,y);
	}
}

void grow()
{
	snake* new_body = (snake*)malloc(sizeof(snake));
	snake* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = new_body;
	new_body->next = NULL;
}
