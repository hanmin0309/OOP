#pragma once
#include <iostream>
#include "conio.h"
#include <windows.h>

#define UP 72 // ��
#define DOWN 80 // �Ʒ�


//#define LEFT 2 
//#define RIGHT 3
using namespace std;

void init_console_size() {
	system("mode con:cols=124 lines=35");
}

void init_game_ui() { // ���Ӹ�ó�� ų�� TItle ����� ��� ����

	cout << " ���޸��� ���� " << endl;

}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� Ŀ�� �ڵ鰡������
	COORD pos;
	pos.X = x; // x��ǥ
	pos.Y = y; // y��ǥ	
	SetConsoleCursorPosition(consoleHandle, pos); // Ŀ�� ��ġ ����
}



int keyControl() {
	char temp = _getch();

	if (temp == 72) // ��
		return UP;
	else if (temp == 80) // �Ʒ�
		return DOWN;
	else if (temp == 27) // ESC
		return 27;
	else if (temp == 13) // Enter
		return 13;
	else
		return -1; // �߸��� �Է�
}

void drawArrow(int x, int y) {
    gotoxy(x, y);
    printf(">");
}

void clearArrow(int x, int y) {
    gotoxy(x, y);
    printf(" "); // ���� ��ġ�� '>'�� ����
}

int menuDraw() {
    int x = 50;
    int y = 15;
    int arrowX = x + 4; // '>' ��ȣ ��ġ
    int currentY = y + 10; // ���� ���õ� �׸��� y��ǥ

    cout << "===========================================================================================================================\n" << endl;
    gotoxy(x, y);
    printf("�ƹ�ư ���޸��� ������\n");

    gotoxy(x - 4, y + 2);
    cout << "����Ϸ��� �ƹ� Ű�� ��������...";

    gotoxy(x + 4, y + 10);
    printf("  ���ӽ��� ");

    gotoxy(x + 6, y + 12);
    printf("�̾��ϱ� ");

    gotoxy(x + 6, y + 14);
    printf("  ����	\n\n");
    cout << "==========================================================================================================================\n" << endl;

    // ó���� '>' ǥ�ø� �ٷ� �׸���
    drawArrow(arrowX, currentY);

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP:
            if (currentY > y + 10) { // �ּ� ��ġ ����
                clearArrow(arrowX, currentY);
                currentY -= 2; // �� �� ���� �̵�
                drawArrow(arrowX, currentY);
            }
            break;
        case DOWN:
            if (currentY < y + 14) { // �ִ� ��ġ ����
                clearArrow(arrowX, currentY);
                currentY += 2; // �� �� �Ʒ��� �̵�
                drawArrow(arrowX, currentY);
            }
            break;
        case 13: // Enter
            system("cls");
            if (currentY == y + 10) return 1; // ���ӽ���
            else if (currentY == y + 12) return 2; // �̾��ϱ�
            else if (currentY == y + 14) return 3; // ����
            break;
        }
    }
}


/*
�������Ʈ
https://geundung.dev/14?category=699626 => ȭ�� �޴��� ����
https://geundung.dev/15?category=699626 =>Ű���� �̺�Ʈ ó��
*/