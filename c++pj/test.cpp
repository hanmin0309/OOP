#include "horse.h"
#include "training.h"
#include "UI.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

const int MAX_MONTH = 36;
const int startStat = 100.0;

using namespace std;

horse select_horse();
void print_basic(int month, horse* player, training& trainer);

int main() { //cols ���� , lines ���� cols=140 lines=30
    int start_format;
    init_console_size(); // �ܼ� ũ�� �ʱ�ȭ
	//init_game_ui(); // UI �ʱ�ȭ
    start_format = menuDraw();
    if (start_format == 1)
    {
        system("cls");
    }
    else if (start_format == 2) {
        //save&load
    }
    else
        exit(1);
        
            
    
	
    srand(static_cast<unsigned>(time(nullptr)));

    horse player = select_horse();
    // Ʈ���̳� ��ü ����
    training trainer(player);

    Sleep(500);
    system("cls");

	


    for (int i = 0; i < MAX_MONTH; i++) {
        print_basic(i, &player, trainer);
        Sleep(500);
        system("cls");
    }

    return 0;
}

horse select_horse() {
    int x = 46;
   
    gotoxy(x,15);
    cout << "1. ���ָ� ��ũ���׸���\n";
    gotoxy(x, 17);
    cout << "2. ���ึ Ʈ���� ũ���\n"; //�̸�Ȯ���ʿ�
    gotoxy(x, 19);
    cout << "3. ���Ը� ������긣\n";
    gotoxy(x, 21);
    cout << "4. ���Ը� ��� ��\n";
    gotoxy(x, 23);
    cout << "���۸��� ���ÿ� (1 ~ 4): ";

    while (true) {
        int n;
        cin >> n;
        switch (n) {
        case 1: return horse("aaa", 0, startStat, startStat, startStat, startStat);
        case 2: return horse("aaa", 1, startStat, startStat, startStat, startStat);
        case 3: return horse("aaa", 2, startStat, startStat, startStat, startStat);
        case 4: return horse("aaa", 3, startStat, startStat, startStat, startStat);
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���: ";
        }
    }
}

void print_basic(int month, horse* player, training& trainer) {
    cout << "=============================================\n"
        << "Month " << month << " / " << MAX_MONTH << "\n";
    cout << "=============================================\n\n";

    cout << "�λ�Ȯ�� : " << trainer.injury_percent(*player) << "%\n\n";

    cout << "1) ���ǵ� �Ʒ�\t2) �Ŀ� �Ʒ�\t3) �ټ� �Ʒ�\t4) ������ �Ʒ�\t5) �޽�\n";
    while (true) {
        int n;
        cin >> n;
        switch (n) {
        case 1: trainer.training_speed(*player);      return;
        case 2: trainer.training_power(*player);      return;
        case 3: trainer.training_perseverance(*player); return;
        case 4: trainer.training_endurance(*player);  return;
        case 5: trainer.rest(*player);                return;
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���: ";
        }
    }
}
