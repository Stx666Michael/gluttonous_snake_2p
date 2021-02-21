#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
 
#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define put 'e'

#define up2 'i'
#define down2 'k'
#define left2 'j'
#define right2 'l'
#define put2 'o'

#define top 0
#define bottom 48
#define leftside 20
#define rightside 116

void welcome();
void gotoxy(int x, int y);
void gotoprint(int x, int y);
void gotodelete(int x, int y);
void creatgraph();
void creatfood();
int ClickControl();
void CursorInvisible();
int Judge();
void Finish();
void MovingBody();
void ChangeBody(int x, int y);
void Eating();
void drop();
void grow();
void gotoprint0(int x, int y);
void gotoprint2(int x, int y);
void creatfood2();
void Finish2();
void MovingBody2();
void ChangeBody2(int x, int y);
void Eating2();
void drop2();
void grow2();

typedef struct Snakes
{
	int x;
	int y;
	struct Snakes* next;
}snake;

struct Food
{
	int x;
	int y;
}food, food2;

snake* head;
snake* waste;
char click, click_, _click;

snake* head2;
snake* waste2;
char click2, click2_, _click2;
