#include "tcs.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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