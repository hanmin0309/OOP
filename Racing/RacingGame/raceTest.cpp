// race test.cpp

#include "race.h"
#include <ctime>
#include <windows.h>


int main() {
    SetConsoleCP(CP_UTF8);               // 입력 인코딩도 UTF-8
    SetConsoleOutputCP(CP_UTF8);         // 출력 인코딩도 UTF-8
    
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 초기화

    // 플레이어 말 생성 (이름, 품종, spd, pow, sta, guts)
    horse playerHorse("썬더볼트", 1, 1000, 950, 900, 850);

    // 레이스 객체 생성 (플레이어 말, 티어)
    int tier = 6; // 티어 값
    Race race(playerHorse, tier);

    // 레이스 시작
    race.start();

    // 결과 출력
    race.show_race_summary();

    return 0;
}
