#include "tcs.h"

void Pos(int x, int y) {     //���ù��λ��
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void Setcolor(int color) {//  ʵ�ֲ�ɫ�ĺ���  
	SetConsoleTextAttribute(hConsole, color);
}

void HideCursor() {    //���ع��
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

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
	while ((key = _getch()) != ENTER) {
		if (GetAsyncKeyState(VK_UP))
			key = U;
		else if (GetAsyncKeyState(VK_DOWN))
			key = D;
		if (key == U && option > 1) option--;
		if (key == D && option < 2) option++;
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

void CreateMap() {             //��ӡ��ͼ
	int i;
	Setcolor(11);
	for (i = 0; i < 38; i = i + 2) {  //��ӡ���±߿�
		Pos(i, 0);
		printf("%c%c", 0xa8, 0x80);
		Pos(i, 19);
		printf("%c%c", 0xa8, 0x80);
	}
	for (i = 1; i < 19; i++) {
		Pos(0, i);
		printf("%c%c", 0xa8, 0x80);
		Pos(36, i);
		printf("%c%c", 0xa8, 0x80);
	}
	if (sleeptime == 200) {//��ӡ�ڶ��ض����ǽ��
		for (i = 0; i < 5; i++) {
			Pos(28, i + 3);
			printf("%c%c", 0xa8, 0x80);
		}
	}
	else if (sleeptime == 100) {//��ӡ�����ض����ǽ��
		for (i = 0; i < 5; i++) {
			Pos(28, i + 3);
			printf("%c%c", 0xa8, 0x80);
			Pos(4, i + 11);
			printf("%c%c", 0xa8, 0x80);
		}
	}
	Setcolor(15);
}

void MarkMap() {             //���
	int i, j;
	for (i = 0; i < 19; i++)
		for (j = 0; j < 36; j++)
			str[i][j] = FLOOR;
	for (j = 0; j <= 36; j = j + 2) {
		str[0][j] = WALL;
		str[19][j] = WALL;
	}
	for (i = 0; i <= 19; i++) {
		str[i][0] = WALL;
		str[i][36] = WALL;
	}
	i = 0;
	if (sleeptime == 200) {//���ĵڶ��صı�ǵ�ͼ
		for (i = 0; i < 5; i++) {
			str[i + 3][28] = WALL;
		}
	}
	else if (sleeptime == 100) {//���ĵ����صı�ǵ�ͼ
		for (i = 0; i < 5; i++) {
			str[i + 3][28] = WALL;
			str[i + 11][4] = WALL;
		}
	}
}

void AddSnake(int a, int b) {    //����һ����ͷ 
	snake *temp = (snake *)malloc(sizeof(snake));
	temp->x = a;
	temp->y = b;
	temp->next = NULL;
	if (head == NULL) {
		tail = head = temp;
		head->next = NULL;
	}
	else {
		head->next = temp;
		temp->previous = head;
		head = head->next;
	}
	str[b][a] = SNAKE;
	Pos(a, b);
	printf("%c%c", 0xa8, 0x80);
	length++;
}

void CreateSnake() {     //��ʼ������ 
	AddSnake(4, 4);
	AddSnake(6, 4);
	AddSnake(8, 4);
	AddSnake(10, 4);
	length = 4;
}

void DeleteTail() {    //ɾ��β�ڵ� 
	struct snake *temp = NULL;
	Pos(tail->x, tail->y);
	printf("  ");
	str[tail->y][tail->x] = FLOOR;
	temp = tail;
	tail = tail->next;
	tail->previous = NULL;
	free((void *)temp);
	length--;
}

void CreateFood() {
	int food_x, food_y;
	srand((unsigned int)time(0));
	food_x = rand() % 34 + 1;
	while (food_x % 2 != 0) food_x = rand() % 34 + 1;
	food_y = rand() % 18 + 1;
	while (str[food_y][food_x] != FLOOR) {
		food_x = rand() % 34 + 1;
		while (food_x % 2 != 0) food_x = rand() % 34 + 1;
		food_y = rand() % 18 + 1;
	}
	str[food_y][food_x] = FOOD;
	Setcolor(14);
	Pos(food_x, food_y);
	printf("��");
	Setcolor(15);
}

void CreateMine() {
	int mine_x, mine_y;
	srand((unsigned int)time(0));
	mine_x = rand() % 34 + 1;
	while (mine_x % 2 != 0) mine_x = rand() % 34 + 1;
	mine_y = rand() % 18 + 1;
	while (str[mine_y][mine_x] != FLOOR) {
		mine_x = rand() % 34 + 1;
		while (mine_x % 2 != 0) mine_x = rand() % 34 + 1;
		mine_y = rand() % 18 + 1;
	}
	str[mine_y][mine_x] = MINE;
	Setcolor(12);
	Pos(mine_x, mine_y);
	printf("��");
	Setcolor(15);
}

void CreatePoison() {
	int count_x = 0, count_y = 0;
	int j = 0, flag = 1, i;
	srand((unsigned)time(NULL));
	while (count_x < 10) {
		poison_x = rand() % 34 + 1;
		while (poison_x % 2 != 0) poison_x = rand() % 34 + 1;
		for (j = 0; j < 10; j++) {
			if (poison_x == rand_num_x[j]) {
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
		if (flag) {
			rand_num_x[count_x] = poison_x;
			count_x++;
		}
	}
	while (count_y < 10) {
		poison_y = rand() % 18 + 1;
		for (j = 0; j < 10; j++) {
			if (poison_y == rand_num_y[j]) {
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
		if (flag) {
			rand_num_y[count_y] = poison_y;
			count_y++;
		}
	}
	if (count % 2 == 0) {
		for (j = 0; j < 10; j++) {
			if (str[rand_num_y[j]][rand_num_x[j]] == FLOOR) {
				str[rand_num_y[j]][rand_num_x[j]] = POISON;
				Pos(rand_num_x[j], rand_num_y[j]);
				Setcolor(8);
				printf("��");
			}
		}
	}
	else if (count != 2) {
		for (i = 0; i < 38; i = i + 2)
			for (j = 1; j < 19; j++) {
				if (str[j][i] == POISON) {
					Pos(i, j);
					printf("  ");
					str[j][i] = FLOOR;
				}
			}
	}
	Setcolor(15);
}

void Shine() {   //������˸����
	int i, j;
	if (count <= 50) {
		if (count % 2 == 0) {
			for (j = 0; j < 10; j++) {
				if (str[rand_num_y[j]][rand_num_x[j]] == FLOOR) {
					str[rand_num_y[j]][rand_num_x[j]] = POISON;
					Pos(rand_num_x[j], rand_num_y[j]);
					Setcolor(8);
					printf("��");
				}
			}
		}
		else if (count != 2) {
			for (i = 0; i < 38; i = i + 2)
				for (j = 1; j < 19; j++) {
					if (str[j][i] == POISON) {
						Pos(i, j);
						printf("  ");
						str[j][i] = FLOOR;
					}
				}
		}
	}
	else if (count > 50) {
		for (i = 0; i < 38; i = i + 2)
			for (j = 1; j < 19; j++) {
				if (str[j][i] == POISON) {
					Pos(i, j);
					printf("  ");
					str[j][i] = FLOOR;
				}
			}
	}
	Setcolor(15);
}

void SnakeMove() {
	int a, b, i, j;
	a = head->x;
	b = head->y;
	switch (direction) {
	case(U):b--; break;
	case(D):b++; break;
	case(L):a = a - 2; break;
	case(R):a = a + 2; break;
	}
	int t = str[b][a];
	if (t == FLOOR) {
		AddSnake(a, b);
		DeleteTail();
	}
	else if (t == WALL) {
		end = 2;
		EndGame();
	}
	else if (t == FOOD) {
		AddSnake(a, b);
		CreateFood();
		score = score + 10;
		str[b][a] = SNAKE;
	}
	else if (t == MINE) {
		if (length == 1) {
			end = 3;
			score = score - 10;
			EndGame();
		}
		else {
			AddSnake(a, b);
			str[b][a] = SNAKE;
			if (length % 2 == 0) i = length / 2;
			else i = (length - 1) / 2;
			j = length;
			while (j > i) {
				DeleteTail();
				j--;
			}
			score = score - 10;
			CreateMine();
		}
	}
	else if (t == POISON) {
		if (length == 1) {
			end = 4;
			score = score - 5;
			EndGame();
		}
		else {
			AddSnake(a, b);
			str[b][a] = SNAKE;
			DeleteTail();
			DeleteTail();
			score = score - 5;
		}
	}
	else if (t == SNAKE) {
		end = 1;
		EndGame();
	}

}

void pause() {//��ͣ
	while (1) {
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE)) {
			break;
		}
	}
}

void RunGame() {
	if (sleeptime == 400) level(1);
	if (sleeptime == 200) level(2);
	if (sleeptime == 100) level(3);
}
void init(int n) {//����Ϸ���̵ĳ�ʼ��
	CreateMap();
	MarkMap();
	CreateSnake();
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
	CreateFood();
	CreatePoison();
	CreateFood();
	for(int i=0;i<n;i++){
		CreateMine();
	}
	CreateFood();
	pause();
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
	Setcolor(15);
	exit(0);
}

void Save() {
	if ((mem = fopen("memory.txt", "wb")) == NULL) {
		printf("�޷���memory.txt!\n");
		fclose(mem);
	}
	else {
		fwrite(&sleeptime, sizeof(sleeptime), 1, mem);
		fwrite(&score, sizeof(score), 1, mem);
		fclose(mem);
	}
}

void Load() {
	if ((mem = fopen("memory.txt", "rb")) == NULL) {//��ȡ��Ϸ�浵
		printf("\n\n\n\n\t\t�޴浵\n");
		fclose(mem);
	}
	else {
		fread(&sleeptime, sizeof(sleeptime), 1, mem);
		fread(&score, sizeof(score), 1, mem);
		fclose(mem);
	}
}


void ScoreSave() {
	int i;
	if ((fp = fopen("���а�.txt", "ab+")) == NULL) {
		printf("�޷������а�.txt!\n");
		fclose(fp);
	}
	else {
		Pos(12, 5);
		printf("��������ҵ����֣�\n\n\t\t");
		scanf("%s", temp.name);
		fp = fopen("���а�.txt", "ab+");
		fread(&person[0], sizeof(person[0]), 1, fp);
		fread(&person[1], sizeof(person[1]), 1, fp);
		fread(&person[2], sizeof(person[2]), 1, fp);
		fclose(fp);
		if (person[0].grade == 0)
		{
			person[0].grade = score;
			person[1].grade = 0;
			person[2].grade = 0;
			strcpy(person[0].name, temp.name);
		}
		else if (person[1].grade == 0) {
			person[1].grade = score;
			person[2].grade = 0;
			strcpy(person[1].name, temp.name);
		}
		else if (person[2].grade == 0) {
			person[2].grade = score;
			strcpy(person[2].name, temp.name);
		}
		else if (score > person[2].grade) {
			person[2].grade = score;
			strcpy(person[2].name, temp.name);
		}
		if (person[2].grade > person[1].grade) {
			t.grade = person[2].grade;
			person[2].grade = person[1].grade;
			person[1].grade = t.grade;
			strcpy(t.name, person[2].name);
			strcpy(person[2].name, person[1].name);
			strcpy(person[1].name, t.name);
		}
		if (person[1].grade > person[0].grade) {
			t.grade = person[1].grade;
			person[1].grade = person[0].grade;
			person[0].grade = t.grade;
			strcpy(t.name, person[1].name);
			strcpy(person[1].name, person[0].name);
			strcpy(person[0].name, t.name);
		}
		if ((fp = fopen("���а�.txt", "wb")) == NULL) {
			printf("�޷������а�.txt!\n");
			fclose(fp);
		}
		else {
			for (i = 0; i < 3; i++)
				fwrite(&person[i], sizeof(savescore), 1, fp);
			fclose(fp);
		}
	}
	printf("\n\n\t  ");
	system("cls");
}

void ScoreLoad() {
	int i, flag = 0;
	if ((fp = fopen("���а�.txt", "rb+")) == NULL) {
		printf("\n\n\n\t\t\t\t  ������Ϸ��¼\n");
		fclose(fp);
	}
	else {
		fp = fopen("���а�.txt", "rb+");
		for (i = 0; i < 3; i++)
			fread(&person[i], sizeof(savescore), 1, fp);
		Pos(50, 5);
		printf("   ���а�\n");
		for (i = 0; i < 3; i++) {
			Pos(50, 7 + 2 * i);
			printf("��%d��  %-10s��%6d", i + 1, person[i].name, person[i].grade);
			//}
		}
		fclose(fp);
	}
}

int main() {
	system("mode con cols=100 lines=30");
	system("COLOR 0B"); //���ñ���
	HideCursor();//���ع��
	FirstPage();//��Ϸ��ҳ
	Choose();
	EndGame();
	system("pause");
	return 0;
}