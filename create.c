#include <stdio.h>
#include "snake.h"

void creatgraph()
{
	int i;

    for (i = leftside; i < rightside+2; i += 2)
    {
        gotoprint0(i, top);
        gotoprint0(i, bottom);
    }
    
	for (i = top+1; i < bottom; i++)
    {
        gotoprint0(leftside, i);
        gotoprint0(rightside, i);
    }

    head = (snake*)malloc(sizeof(snake));
    waste = (snake*)malloc(sizeof(snake));
    snake* p = (snake*)malloc(sizeof(snake));
    snake* q = (snake*)malloc(sizeof(snake));
    
    head2 = (snake*)malloc(sizeof(snake));
    waste2 = (snake*)malloc(sizeof(snake));
    snake* m = (snake*)malloc(sizeof(snake));
    snake* n = (snake*)malloc(sizeof(snake));
    
	head->x = leftside+(rightside-leftside)/3;
    head->y = top+(bottom-top)/3;
    waste->x = leftside;
    waste->y = top;
    
	head2->x = rightside-(rightside-leftside)/3;
    head2->y = bottom-(bottom-top)/3;
    waste2->x = rightside;
    waste2->y = bottom;
    
    head->next = p;
    p->next = q;
    q->next = NULL;
    waste->next = NULL;
    
    head2->next = m;
    m->next = n;
    n->next = NULL;
    waste2->next = NULL;
}

void creatfood()
{
	int flag = 0;
	while (!flag)
	{
		flag = 1;
		srand((int)time(NULL));
		food.y = rand() % (bottom-top-1) + top + 1;
		food.x = rand() % (rightside-leftside-3) + leftside + 1;
		if (food.x % 2 != 0)
			food.x += 1;
		snake* judge = head;
		snake* judge_ = waste;
		snake* judge2 = head2;
		snake* judge2_ = waste2;
		while (judge->next != NULL)
		{
			if (food.x == judge->x && food.y == judge->y)
				flag = 0;
			judge = judge->next;
		}
		while (judge_->next != NULL)
		{
			if (food.x == judge_->x && food.y == judge_->y)
				flag = 0;
			judge_ = judge_->next;
		}
		while (judge2->next != NULL)
		{
			if (food.x == judge2->x && food.y == judge2->y)
				flag = 0;
			judge2 = judge2->next;
		}
		while (judge2_->next != NULL)
		{
			if (food.x == judge2_->x && food.y == judge2_->y)
				flag = 0;
			judge2_ = judge2_->next;
		}
		if (food.x == food2.x && food.y == food2.y)
			flag = 0;
	}
	gotoxy(food.x, food.y);
	printf("กั");
}

void creatfood2()
{
	int flag = 0;
	while (!flag)
	{
		flag = 1;
		srand((int)time(NULL));
		food2.y = rand() % (bottom-top-1) + top + 1;
		food2.x = rand() % (rightside-leftside-3) + leftside + 1;
		if (food2.x % 2 != 0)
			food2.x += 1;
		snake* judge = head;
		snake* judge_ = waste;
		snake* judge2 = head2;
		snake* judge2_ = waste2;
		while (judge->next != NULL)
		{
			if (food2.x == judge->x && food2.y == judge->y)
				flag = 0;
			judge = judge->next;
		}
		while (judge_->next != NULL)
		{
			if (food2.x == judge_->x && food2.y == judge_->y)
				flag = 0;
			judge_ = judge_->next;
		}
		while (judge2->next != NULL)
		{
			if (food2.x == judge2->x && food2.y == judge2->y)
				flag = 0;
			judge2 = judge2->next;
		}
		while (judge2_->next != NULL)
		{
			if (food2.x == judge2_->x && food2.y == judge2_->y)
				flag = 0;
			judge2_ = judge2_->next;
		}
		if (food2.x == food.x && food2.y == food.y)
			flag = 0;
	}
	gotoxy(food2.x, food2.y);
	printf("กั");
}
