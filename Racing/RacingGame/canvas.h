#ifndef CANVAS_H
#define CANVAS_H
#include <iostream>

class Canvas {
private:
    static const int WIDTH = 61; // 마지막에 | 결승선임 (경기장 크기는 60)
    static const int HEIGHT = 7;
    int map[HEIGHT][WIDTH];

public:
    Canvas() {
        for (int y = 0; y < HEIGHT; ++y)
            for (int x = 0; x < WIDTH; ++x) {
                map[y][x] = 0;  // 맵을 모두 초기화
            }
        for (int i = 0; i < HEIGHT; ++i) {
            map[i][60] = -1;
        }
    }

    void set_tile(int y, int x, int posX) { // y는 말이 달리는 라인, x는 이동할 위치, posX는 현재위치
        map[y][posX] = 0; // 현재위치 0으로 초기화
        map[y][x] = y + 1;  // 말이 이동한 위치 설정
    }

    void printMap() { // 맵 출력 함수
        for (int h = 0; h < HEIGHT; h++) {
            bool isH = false;
            for (int w = 0; w < WIDTH; w++) {
                if (map[h][w] == -1) std::cout << '|';
                else if (map[h][w] != 0) {
                    std::cout << map[h][w]; isH = true;
                }
                else if (!isH)std::cout << '.';
                else std::cout << ' ';
            }
            std::cout << '\n';
        }
    } 
};
#endif //CANVAS_H