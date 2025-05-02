#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

#define BASELINE 1000

enum HorseType { PLAYER, CPU };

class Horse {
private:
    HorseType type;
    std::string name;
    int breed; // 0: 도주 / 1: 선행 / 2: 선입 / 3: 추입

    int spd = 0;
    int pow = 0;
    int sta = 0;
    int guts = 0;

    int prev_pos = 0;
    int curr_pos = 0;
    double decimal_point = 0.0;

    double stat_mod[3];  // 초/중/후반 스탯 보정
    double breed_mod[3]; // 초/중/후반 품종 보정

public:
    // CPU용 생성자
    Horse(int breed, int tier) : type(CPU), name(""), breed(breed) {
        set_ai_stats(breed, tier);
        set_modifiers(breed);
    }

    // 플레이어용 생성자
    Horse(std::string name, int breed, int spd, int pow, int sta, int guts)
        : type(PLAYER), name(name), breed(breed),
        spd(spd), pow(pow), sta(sta), guts(guts) {
        set_modifiers(breed);
    }

    // AI 스탯 설정
    void set_ai_stats(int breed, int tier) {
        switch (breed) {
        case 0: spd = (1100 + rand() % 101) / tier;
            pow = (1000 + rand() % 101) / tier;
            sta = (750 + rand() % 101) / tier;
            guts = (650 + rand() % 101) / tier; break;
        case 1: spd = (1050 + rand() % 101) / tier;
            pow = (900 + rand() % 101) / tier;
            sta = (950 + rand() % 101) / tier;
            guts = (800 + rand() % 101) / tier; break;
        case 2: spd = (950 + rand() % 101) / tier;
            pow = (850 + rand() % 101) / tier;
            sta = (1000 + rand() % 101) / tier;
            guts = (850 + rand() % 101) / tier; break;
        case 3: spd = (900 + rand() % 101) / tier;
            pow = (800 + rand() % 101) / tier;
            sta = (900 + rand() % 101) / tier;
            guts = (1100 + rand() % 101) / tier; break;
        }
    }

    // 품종 특성 설정
    void set_modifiers(int breed) {
        static double s_mod[4][3] = {
            {1.5, 1.3, 1.2},
            {1.4, 1.4, 1.2},
            {1.3, 1.4, 1.3},
            {1.2, 1.3, 1.5}
        };
        static double b_mod[4][3] = {
            {1.9, 1.7, 1.4},
            {1.8, 1.8, 1.6},
            {1.6, 1.8, 1.8},
            {1.4, 1.7, 1.9}
        };
        for (int i = 0; i < 3; i++) {
            stat_mod[i] = s_mod[breed][i];
            breed_mod[i] = b_mod[breed][i];
        }
    }

    // 이동
    void move() {
        int section = position();
        int section_stat = (section == 0) ? pow : (section == 1) ? sta : guts;

        double base_speed = static_cast<double>(spd) / BASELINE;
        double random_factor = 2.5 + (rand() % 11) / 10.0;
        double stat_bonus = (static_cast<double>(section_stat) / BASELINE) * stat_mod[section];
        double breed_bonus = breed_mod[section] * stat_bonus;

        double move_distance = base_speed * random_factor + breed_bonus + decimal_point;
        decimal_point = fmod(move_distance, 1.0);
        prev_pos = curr_pos;
        curr_pos += static_cast<int>(move_distance);
    }

    // 훈련 함수 (플레이어 전용)
    void train_spd(int val) { if (type == PLAYER) spd += val; }
    void train_pow(int val) { if (type == PLAYER) pow += val; }
    void train_sta(int val) { if (type == PLAYER) sta += val; }
    void train_guts(int val) { if (type == PLAYER) guts += val; }

    // 위치 구간
    int position() const {
        if (curr_pos <= 19) return 0;
        else if (curr_pos <= 39) return 1;
        else return 2;
    }

    // 게터
    int get_position() const { return curr_pos; }
    int get_prev_position() const { return prev_pos; }
    std::string get_name() const { return name; }
    HorseType get_type() const { return type; }

    // 디버깅 출력
    void print_stats() const {
        std::cout << "[Horse Stats] Type: " << (type == PLAYER ? "PLAYER" : "CPU")
            << ", Breed: " << breed << ", SPD: " << spd << ", POW: " << pow
            << ", STA: " << sta << ", GUTS: " << guts << std::endl;
    }
};
