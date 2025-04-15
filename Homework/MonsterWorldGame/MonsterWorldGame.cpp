#include "MonsterWorld.h"
#include <time.h>

int Monster::count = 0;

void main()
{
	srand((unsigned int)time(NULL));
	int w = 50, h = 7;
	MonsterWorld game(w, h);

	game.add(new Monster("몬스터", "※", rand() % w, rand() % h));
	game.add(new Monster("도깨비", "◎", rand() % w, rand() % h));
	game.add(new Monster("별그대", "★", rand() % w, rand() % h));
	game.add(new Monster("고스트", "♥", rand() % w, rand() % h));
	game.play(500, 10);
	printf("----------게임 종료----------\n");
}