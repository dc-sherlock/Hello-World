#include "tcs.h"

void FirstPage() {        //��Ϸ��ҳ
	printf("\n\n\n\n\n\t��ӭ����̰������Ϸ��\n");
	printf("\n\t���÷����������������\n\n\t");
	printf(" ���س�����ʼ��Ϸ\n\n\t");
	getchar();
	system("cls");
}

void Choose() {
	int key, option = 1;    //Ĭ�����½���Ϸ 
	Pos(5, 5);
	printf("����Ϸ");
	Pos(13, 5);
	printf("->");
	Pos(5, 7);
	printf("������Ϸ");
    Pos(5,9);
    printf("��ESC�˳���Ϸ");
	while ((key = _getch()) != ENTER) {
		if (GetAsyncKeyState(VK_UP))
			key = U;
		else if (GetAsyncKeyState(VK_DOWN))
			key = D;
		if (key == U && option > 1) option--;
		if (key == D && option < 2) option++;
        if (key == ESC) {
			system("cls");
			Setcolor(15);
			exit(0);
		}
		if (option == 1) {
			Pos(13, 5);
			printf(" ->");
			Pos(13, 7);
			printf("   ");
		}
		else {
			Pos(13, 7);
			printf(" ->");
			Pos(13, 5);
			printf("   ");
		}
	}
	system("cls");
	if (option == 1) ChooseLevel();//ѡ��ؿ�
	else {
		Load();
		CreateMap();
		MarkMap();
		RunGame();
		system("pause");
	}
}

void ChooseLevel() {
	char key;
	printf("\n\n\n\t��ѡ��ؿ���(�Ѷ�1-3)\n\n\n\t(����Ҫ�˳�������n)\n\n\n\t\t");
	scanf("%c", &key);
	switch (key) {
	case('1'):system("cls");  level(1); break;
	case('2'):system("cls");   level(2); break;
	case('3'):system("cls");  level(3); break;
	case('n'):end = 5; EndGame(); break;
	}
	printf("\n\n\t");
	system("cls");
}


