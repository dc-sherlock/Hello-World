#include "tcs.h"

FILE * mem;     //��Ϸ�浵�ļ����
FILE *fp;

struct savescore {
	char name[20];
	int grade;
}person[3], temp, t;

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

void Load() {//��ȡ��Ϸ�浵
	if ((mem = fopen("memory.txt", "rb")) == NULL) {
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
		}
		fclose(fp);
	}
}
