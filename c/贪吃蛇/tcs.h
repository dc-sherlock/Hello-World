#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���

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
}*head = NULL, *tail = NULL;

struct savescore {
	char name[20];
	int grade;
}person[3], temp, t;


int poison_x, poison_y;
int rand_num_x[10] = { 0 }, rand_num_y[10] = { 0 };
int end = 0, length = 0, score = 0, count = 0;
int str[20][40];
int direction = R;
int sleeptime = 400;//ÿ�����е�ʱ����
FILE * mem;     //��Ϸ�浵�ļ����
FILE *fp;

void FirstPage();
void Choose();
void ChooseLevel();
void CreateMap();
void MarkMap();
void AddSnake(int a, int b);
void CreateSnake();
void DeleteTail();
void CreateFood();
void CreateMine();
void CreatePoison();
void Shine();
void SnakeMove();
void pause();
void RunGame();
void init(int n);
void gaming(int n);
void level(int n);
void Level_1();
void Level_2();
void Level_3();
void EndGame();
void Save();
void Load();
void ScoreSave();
void ScoreLoad();