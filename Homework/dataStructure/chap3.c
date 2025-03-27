#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void quiz4();
void quiz5();
void quiz6();
void quiz7();
void quiz8();
void quiz9();
void quiz10();
void quiz11();
void quiz12();

void main()
{
    bool isGameOver = false;
    int num;

    printf("게임소프트웨어학과 - 5723717 - 조홍준\n\n");

    while (!isGameOver)
    {
        printf("문제의 번호(4 ~ 12)를 입력하세요(0을 입력하면 종료): ");
        scanf_s("%d", &num);

        switch (num)
        {
        case 0:
            printf("\n프로그램을 종료합니다.\n");
            printf("\n게임소프트웨어학과 - 5723717 - 조홍준\n");
            isGameOver = true;
            break;

        case 4: quiz4();
            break;

        case 5: quiz5();
            break;

        case 6: quiz6();
            break;

        case 7: quiz7();
            break;

        case 8: quiz8();
            break;

        case 9: quiz9();
            break;

        case 10: quiz10();
            break;

        case 11: quiz11();
            break;

        case 12: quiz12();
            break;

        default:
            printf("숫자를 잘못 입력하였습니다.\n");
        }
    }
}

void quiz4()
{
    printf("04 크기가 10인 배열 two[]를 선언하고 여기에 2의 제곱 값을 저장해보자.\n");
    printf("즉, 배열의 첫 번째 요소에는 2⁰을 저장하고 두 번째 요소에는 2¹값을 저장한다. 마지막 요소에는 2⁹값을 저장한다.\n");
    printf("for 루프를 이용하여 two[] 배열의 전체 요소의 값을 출력하는 프로그램을 작성하라.\n");

    int two[10];

    for (int i = 0; i < 10; i++)
    {
        two[i] = pow(2, i);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("two[%d]의 값: %d\n", i, two[i]);
    }
}

void quiz5()
{
    printf("Quiz 5 : \n");

    printf("struct Person\n");
    printf("{\n");
    printf("    char name[10];\n");
    printf("    int age;\n");
    printf("    float salary;\n");
    printf("};\n");

   struct Person
    {
        char name[10];
        int age;
        float salary;
    };
}

void quiz6()
{
    printf("Quiz 6 : \n");

    typedef struct Complex
    {
        float real;
        float imaginary;
    } Complex;

    Complex c1;
    Complex c2;

    printf("typedef struct Complex\n");
    printf("{\n");
    printf("    float real;\n");
    printf("    float imaginary;\n");
    printf("} Complex;\n");
    printf("\n");
    printf("Complex c1;\n");
    printf("Complex c2;\n");
}

void quiz7()
{
    
}

void quiz8()
{

}

void quiz9()
{

}

void quiz10()
{

}

void quiz11()
{

}

void quiz12()
{

}

