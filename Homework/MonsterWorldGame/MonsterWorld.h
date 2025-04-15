#pragma once
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <windows.h>
#define MAXMONS 8

class MonsterWorld {
	Matrix world;
	int xMax, yMax, nMon, nMove;
	Monster* pMon[MAXMONS];
	Canvas canvas;

	int& Map(int x, int y) { return world.elem(x, y); }

	bool isDone() { return countItems() == 0 || nMon == 0; }

	int countItems() {
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}

	void print() {
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");

		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World (몬스터들의 세상) ]");
		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
		Monster::printCount();
	}

	void checkEnergy() {
		for (int i = 0; i < nMon; ) {
			if (pMon[i]->getEnergy() == 0) {
				delete pMon[i];
				pMon[i] = pMon[--nMon];
				cout << "Monster 하나가 굶어죽습니다" << endl;
			}

			else {
				i++; // 0번자리에 5번이 들어오면 다시 검사를 못하기 때문에, 수동으로 조작하는거임.
			}
		}
	}

public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld()	{ 
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	
	void add(Monster* m) {
		if (nMon < MAXMONS) {
			pMon[nMon++] = m;
		}
	}

	void play(int maxwalk, int wait) {
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				pMon[k]->move(world.Data(), xMax, yMax);
			nMove++;
			print();
			checkEnergy();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};