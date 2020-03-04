#include "tcs.h"

int direction=R,end=0,sleeptime=400;
void pause() {//��ͣ
	while (1) {
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE)) {
			break;
		}
	}
}

void init(int n) {//����Ϸ���̵ĳ�ʼ��
	CreateMap();
	MarkMap();
	CreateSnake();
	count=0;
	printText();
	CreateFood();
	CreatePoison();
	CreateFood();
	for(int i=0;i<n;i++){
		CreateMine();
	}
	CreateFood();
	pause();
}
void printText() {
	Pos(50, 3);
	printf("���ܴ�ǽ������ҧ���Լ�");
	Pos(50, 5);
	printf("���߳��ȴﵽ10ʱ������һ��");
	Pos(50, 7);
	printf("���á�.��.��.���������ߵ��ƶ�,�ո����ͣ");
	Pos(50, 9);
	printf("�����ʳ��Ե�ʳ����������һ����λ,�÷ּ�10��");
	Pos(50, 11);
	printf("��������ף��ȵ������������һ��,�÷ּ�10��");
	Pos(50, 13);
	printf("������ݣ��Ե������������һ����λ,�÷ּ�5��");
}
void gaming(int num){//��ʾ��Ϸ�����У�num:�ؿ���
	while (length<10) {
		count++;
		Shine();
		Pos(50, 15);
		printf("������%d", score);
		SnakeMove();
		Sleep(sleeptime);
		if (GetAsyncKeyState(VK_UP) && direction != D)
			direction = U;
		else if (GetAsyncKeyState(VK_DOWN) && direction != U)
			direction = D;
		else if (GetAsyncKeyState(VK_LEFT) && direction != R)
			direction = L;
		else if (GetAsyncKeyState(VK_RIGHT) && direction != L)
			direction = R;
		else if (GetAsyncKeyState(VK_SPACE))
			pause();
		if (_kbhit()) {
			if (_getch() == ESC) {//��ESC�浵���˳� 
				Save();    //�浵
				free(head);
				system("cls");
				Pos(8, 10);
				printf("�浵��...\n");
				exit(0);
			}
		}
	}
	if (length >= 10) {
		switch (num) {
		case 1:
			sleeptime=200;
			break;
		case 2:
			sleeptime=100;
			break;
		case 3:
			system("cls");
			end = 6;
			EndGame();
		default:
			break;
		}
		system("cls");
		Pos(20, 6);
		printf("��ϲ��ͨ����%d�أ���������%d��",num,num+1);
		Pos(28, 8);
		system("pause");
		system("cls");
		int i, j;
		for (i = 0; i < 38; i = i + 2)
			for (j = 1; j < 19; j++)
				str[j][i] = FLOOR;
		direction = R;
		snake *p, *t;
		p = tail;
		p->previous = NULL;
		for (i = 1; i <= length; i++) {
			t = p;
			p = p->next;
			free((void *)t);
		}
		head = NULL;
		RunGame();
	}

}
//3 food,1 poison,mine(1:3,2:5,3:8)
void level(int num){
	switch (num)
	{
	case 1:
		sleeptime = 400;
		init(3);
		break;
	case 2:
		sleeptime = 200;
		init(5);
		break;
	case 3:
		sleeptime = 100;
		init(8);
		break;
	default:
		break;
	}
	gaming(num);
}
void RunGame() {
	if (sleeptime == 400) level(1);
	if (sleeptime == 200) level(2);
	if (sleeptime == 100) level(3);
}
void EndGame() {
	system("COLOR 0B");
	int option = 1;
	system("cls");
	ScoreSave();
	Pos(10, 6);
	if (end == 1) printf("�Բ�����ҧ���Լ��ˣ���Ϸ������");
	else if (end == 2) printf("�Բ�����ײ��ǽ�ˣ���Ϸ������");
	else if (end == 3)printf("�Բ����㱻����ը���ˣ���Ϸ����");
	else if (end == 4)printf("�Բ����㱻�����ˣ���Ϸ����");
	else if (end == 5)printf("         ��Ϸ����");
	else if (end == 6) printf("    ��ϲ�㣬��Ϸʤ����");
	printf("\n\n\t\t��ĵ÷���%d", score);
	ScoreLoad();
	Pos(12, 10);
	while (getchar() != 'y') {
		printf("�Ƿ������Ϸ?(����y������)\n\n\t\t");
	}
	free(head);
	Setcolor(15);
	exit(0);
}