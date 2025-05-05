#pragma once
#ifndef CANVAS_H
#define CANVAS_H
#include <iostream>

class Canvas {
private:
	static const int WIDTH = 61; // �������� ��¼� ����� ũ��� 60*7
	static const int HEIGHT = 7;
	int map[HEIGHT][WIDTH];

public:
	Canvas() {
		for (int y= 0; y< HEIGHT; ++y)
			for (int x = 0; x < WIDTH; ++x) 
			{
				map[y][x] = 0; // ���� ��� �ʱ�ȭ
			}
		for (int i = 0; i < HEIGHT; ++i) 
		{
			map[i][60] = -1;
		}
	}


void setTile(int y, int x, int posX) {
	map[y][posX] = 0; // ���� ��ġ 0���� �ʱ�ȭ
	map[y][x] = y + 1;
}

void printMap() // ������Լ�
{
	for (int h = 0; h < WIDTH; h++) {
		bool isH = false;
		for (int w = 0; w < WIDTH; w++)
		{
			if (map[h][w] == -1)std::cout << '|';
			else if (map[h][w] != 0)
			{
				std::cout << map[h][w]; isH = true;
			}
			else if (!isH)std::cout << '.';
			else std::cout << ' ';
		}
		std::cout << '\n';
	}
}
};
#endif // !CANVAS_H

