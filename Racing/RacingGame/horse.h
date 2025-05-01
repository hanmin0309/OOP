#ifndef HORSE_H
#define HORSE_H
#include<iostream>
#include<string>
#include<cmath>

#define BASELINE 1000 // 스탯 기준치(이동로직 계산 사용)

class horse_p {
protected:
    double spd;     //스피드
    double pow;     //파워
    double guts;    //근성
    double sta; //지구력

    double breedMod[3]; // 특성 보정치 0 초 1 중 2 후
    double statMod[3];//스탯 보정치 0초 1중 2후

    int index_L; //인덱스전
    int index_N; //인덱스 현
    double decimal_Point; //달리는 로직에 쓰이는 소숫점 저장용 
 
    std::string name; // 말이름 
    std::string type; //말종류
public: 
    horse_p(double spd, double pow, double guts, double sta)
        : spd(spd), pow(pow), guts(guts), sta(sta),
        index_L(0),index_N(0), decimal_Point(0) {
        breedMod[0] = 0; breedMod[1] = 0; breedMod[2] = 0;
        statMod[0] = 0; statMod[1] = 0; statMod[2] = 0;
        name = "기본";
        type = "기본";
    }

    double get_spd() { return spd; }
    double get_guts() { return guts; }
    double get_pow() { return pow; }
    double get_sta() { return sta; }
    std::string get_name() { return name; }
    int get_index_L() { return index_L; }
    int get_index_N() { return index_N; }
    void set_spd(double spd) { this->spd += spd; }
    void set_guts(double guts) { this->guts += guts; }
    void set_pow(double pow) { this->pow += pow; }
    void set_sta(double sta) { this->sta += pow; }

    int location_where() {//초입 중반 후반 계산 리턴값 1초 2중 3후 
        if (index_N <= 20) return 0;
        else if (index_N <= 40)return 1;
        else return 2;
    } 
    void move() {
        double sM[3] = { statMod[0] * pow, statMod[1] * sta, statMod[2] * guts };
        int n = location_where();
        double distance = (spd / BASELINE) * (2.5 + (rand() % 11) / 10) + breedMod[n] * ( sM[n]/BASELINE) + decimal_Point;
        decimal_Point = fmod(distance, 1);
        index_L = index_N;
        index_N += static_cast<int>(distance);
    }
};


class front_Runner :public horse_p { //도주마
public:
    front_Runner(double spd, double pow, double guts, double sta) : horse_p(spd, pow, guts, sta) {
        breedMod[0] = 1.5; breedMod[1] = 1.3; breedMod[2] = 1.2;
        statMod[0] = 1.9; statMod[1] = 1.7; statMod[2] = 1.4;
        name = "세크리테리엇";
        type = "도주마";
    }
};
class early_Speed :public horse_p { // 선행마
public:
    early_Speed(double spd, double pow, double guts, double sta) : horse_p(spd, pow, guts, sta) {
        breedMod[0] = 1.4; breedMod[1] = 1.4; breedMod[2] = 1.2;
        statMod[0] = 1.8; statMod[1] = 1.8; statMod[2] = 1.6;
        name = "트리플 크라운";
        type = "선행마";
    }
};
class stalker :public horse_p { // 선입마
public:
    stalker(double spd, double pow, double guts, double sta) : horse_p(spd, pow, guts, sta) {
        breedMod[0] = 1.3; breedMod[1] = 1.4; breedMod[2] = 1.3;
        statMod[0] = 1.6; statMod[1] = 1.8; statMod[2] = 1.8;
        name = "오르페브르";
        type = "선입마";
    }
};

class closer :public horse_p { // 추입마
public:
    closer(double spd, double pow, double guts, double sta) : horse_p(spd, pow, guts, sta) {
        breedMod[0] = 1.2; breedMod[1] = 1.3; breedMod[2] = 1.5;
        statMod[0] = 1.4; statMod[1] = 1.7; statMod[2] = 1.9;
        name = "골드 쉽";
        type = "추입마";
    }
};

#endif // !HORSE_H
