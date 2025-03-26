#include <stdio.h>
#include <math.h>

void quiz4()
{
    printf("Quiz 4 : \n");

    int two[10];

    for (int i = 0; i < 10; i++)
    {
        two[i] = pow(2, i);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("two[%d]ÀÇ °ª: %d\n", i, two[i]);
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
    printf("Complex c1\n");
    printf("Complex c2\n;");
}

void quiz7()
{

}





int main()
{
    quiz4();
    quiz5();
    quiz6();
    return 0;
}