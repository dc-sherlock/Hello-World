#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

extern HANDLE hConsole; //��ȡ���

#define U 1
#define D 2
#define L 3 
#define R 4    //�ߵ�״̬��U���� ��D���£�L:�� R����

#define ESC 27
#define ENTER 13
#define FLOOR 0
#define WALL 1
#define SNAKE 2
#define FOOD 3
#define MINE 4
#define POISON 5

struct snake {//�ߵ����ݽṹ
	int x;
	int y;
	struct snake *previous;
	struct snake *next;
};
extern snake *head,*tail;

extern int end , length, score , count ;
extern int str[20][40];
extern int direction;
extern int sleeptime;//ÿ�����е�ʱ����

/*page*/
void Pos(int x, int y);
void Setcolor(int color);
void FirstPage();
void Choose();
void ChooseLevel();
/*map*/
void CreateMap();
void MarkMap();
void CreateFood();
void CreateMine();
void CreatePoison();
void Shine();

/*snake*/
void AddSnake(int a, int b);
void CreateSnake();
void DeleteTail();
void SnakeMove();

/*game*/
void init(int n);
void printText();
void RunGame();
void pause();
void gaming(int n);
void level(int n);
void Level_1();
void Level_2();
void Level_3();
void EndGame();

/*sava_load*/
void Save();
void Load();
void ScoreSave();
void ScoreLoad();