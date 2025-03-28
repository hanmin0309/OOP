#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

	while (!isGameOver)
	{
		printf("게임소프트웨어학과 - 5723717 - 조홍준\n\n");
		printf("문제의 번호(4 ~ 12)를 입력하세요(0을 입력하면 종료): ");
		scanf("%d", &num);

		switch (num)
		{
		case 0:
			printf("프로그램을 종료합니다.\n\n");
			printf("게임소프트웨어학과 - 5723717 - 조홍준\n");
			isGameOver = true;
			break;

		case 4:
			system("cls");
			quiz4();
			break;

		case 5:
			system("cls");
			quiz5();
			break;

		case 6:
			system("cls");
			quiz6();
			break;

		case 7:
			system("cls");
			quiz7();
			break;

		case 8:
			system("cls");
			quiz8();
			break;

		case 9:
			system("cls");
			quiz9();
			break;

		case 10:
			system("cls");
			quiz10();
			break;

		case 11:
			system("cls");
			quiz11();
			break;

		case 12:
			system("cls");
			quiz12();
			break;

		default:
			printf("숫자를 잘못 입력하였습니다.\n");
		}
	}
}

void quiz4()
{
	printf("---------- 문제 ----------\n\n");

	printf("04 크기가 10인 배열 two[]를 선언하고 여기에 2의 제곱 값을 저장해보자.\n");
	printf("즉, 배열의 첫 번째 요소에는 2⁰을 저장하고 두 번째 요소에는 2¹값을 저장한다. 마지막 요소에는 2⁹값을 저장한다.\n");
	printf("for 루프를 이용하여 two[] 배열의 전체 요소의 값을 출력하는 프로그램을 작성하라.\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("int two[10];\n");

	printf("for (int i = 0; i < 10; i++)\n");
	printf("{\n");
	printf("    two[i] = pow(2, i);\n");
	printf("}\n");

	printf("for (int i = 0; i < 10; i++)\n");
	printf("{\n");
	printf("    printf(\"two[%%d]의 값: %%d\\n\", i, two[i]);\n");
	printf("}\n");

	printf("\n---------- 출력결과 ----------\n");

	int two[10];

	for (int i = 0; i < 10; i++)
	{
		two[i] = pow(2, i);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("two[%d]의 값: %d\n", i, two[i]);
	}
	printf("\n---------- 끝 ----------\n\n");
}

void quiz5()
{
	printf("---------- 문제 ----------\n\n");

	printf("05 person이라는 구조체를 만들어보자.\n");
	printf("이 구조체에는 문자 배열로 된 이름, 사람의 나이를 나타내는 정수 값, ");
	printf("각 개인의 월급을 나타내는 float 값 등이 변수로 들어가야 한다.\n\n");

	printf("---------- 정답 ----------\n\n");

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

	printf("\n---------- 끝 ----------\n\n");
}

void quiz6()
{
	printf("---------- 문제 ----------\n\n");

	printf("06 C언어의 typedef를 이용하여 complex라고 하는 새로운 자료형을 정의하라.\n");
	printf("complex 자료형은 구조체로서 float형인 real 변수와 역시 float형인 imaginary 변수를 갖는다.\n");
	printf("complex 자료형으로 변수 c1과 c2를 선언하여보라.\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("typedef struct Complex\n");
	printf("{\n");
	printf("    float real;\n");
	printf("    float imaginary;\n");
	printf("} Complex;\n");
	printf("\n");
	printf("Complex c1 = {143.312, 56.4};\n");
	printf("Complex c2 = {44.2, 231.53};\n");

	typedef struct Complex
	{
		float real;
		float imaginary;
	} Complex;

	Complex c1 = { 143.312, 56.4 };
	Complex c2 = { 44.2, 231.53 };

	printf("\n---------- 끝 ----------\n\n");
}

// Quiz 7 Complex, complex_add(a, b) 선언부
typedef struct Complex
{
	float real;
	float imag;
} Complex;

Complex complex_add(Complex a, Complex b)
{
	Complex c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	printf("결과: %f + %fi\n", c.real, c.imag);

	return c;
}

void quiz7()
{
	printf("---------- 문제 ----------\n\n");

	printf("07 복소수를 구조체로 표현해보자.\n");
	printf("복소수 a와 복소수 b를 받아서 a + b를 계산하는 함수를 작성해보자.\n");
	printf("함수는 구조체를 반환할 수 있다.\n");
	printf("알다시피 복소수는 real + imag * i와 같은 형태를 갖는다.\n\n");


	printf("Complex complex_add(Complex a, Complex b) {\n");
	printf("    ...\n");
	printf("}\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("typedef struct Complex\n");
	printf("{\n");
	printf("    float real;\n");
	printf("    float imag;\n");
	printf("} Complex;\n\n");

	printf("Complex complex_add(Complex a, Complex b)\n");
	printf("{\n");
	printf("    Complex c;\n");
	printf("    c.real = a.real + b.real;\n");
	printf("    c.imag = a.imag + b.imag;\n");
	printf("printf(\"결과: %%f + %%fi\\n\", c.real, c.imag);\n");
	printf("    return c;\n");
	printf("}\n\n");

	printf("Complex a = {1.2, 3.4};\n");
	printf("Complex b = {5.6, 7.8};\n");
	printf("complex_add(a, b);\n");

	printf("\n---------- 실행결과 ----------\n\n");

	Complex a = { 1.2, 3.4 };
	Complex b = { 5.6, 7.8 };

	complex_add(a, b);

	printf("\n---------- 끝 ----------\n\n");
}

// Quiz 8 insert(int array, int loc, int value) 선언부
#define N 10
void insert(int array[], int loc, int value)
{
	int temp = -1;
	for (int i = N - 1; i > loc; i--)
	{
		temp = array[i - 1];
		array[i] = temp;
	}

	array[loc] = value;
}

void quiz8()
{
	printf("---------- 문제 ----------\n\n");

	printf("08 크기가 n인 배열 array에서 임의의 위치 loc에 정수 value를 삽입하는 함수 insert()를 작성하라.\n");
	printf("정수가 삽입되면 그 뒤에 있는 정수들은 한 칸씩 뒤로 밀려야 한다.\n");
	printf("현재 배열에 들어있는 원소의 개수는 items개라고 하자. (여기서 items << n라고 가정)\n\n");

	printf("void insert(int array[], int loc, int value) {\n");
	printf("    ...\n");
	printf("}\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("#define N 10\n\n");

	printf(
		"void insert(int array[], int loc, int value)\n"
		"{\n"
		"    int temp = -1;\n"
		"    for (int i = N - 1; i > loc; i--)\n"
		"    {\n"
		"        temp = array[i-1];\n"
		"        array[i] = temp;\n"
		"    }\n"
		"\n"
		"    array[loc] = value;\n"
		"}\n"
	);

	printf("\n---------- 출력 예시 ----------\n\n");

	printf("int array[N] = { 1, 2, 3, 4, 5, };\n"
		"\n\n"
		"insert(array, 4, 100);\n"
		"\n"
		"for (int i = 0; i < N; i++)\n"
		"{\n"
		"   printf(\"인덱스 %%d번째의 값 : %%d\\n\", i, array[i]);\n"
		"}\n"
	);

	printf("\n---------- 출력 결과 ----------\n\n");

	int array[N] = { 1, 2, 3, 4, 5, };

	insert(array, 4, 100);

	for (int i = 0; i < N; i++)
	{
		printf("인덱스 %d번째의 값 : %d\n", i, array[i]);
	}

	printf("\n---------- 끝 ----------\n\n");
}

void quiz9()
{
	printf("---------- 문제 ----------\n\n");

	printf("09 앞의 문제에서 구현한 insert() 함수의 시간 복잡도는?\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("O(n)\n");

	printf("\n---------- 끝 ----------\n\n");
}

// Quiz 10 insert(int array, int loc) 선언부
#define N 10
void delete(int array[], int loc)
{
	int temp = -1;
	for (int i = loc; i < N - 1; i++)
	{
		temp = array[i + 1];
		array[i] = temp;
	}
}

void quiz10()
{
	printf("---------- 문제 ----------\n\n");

	printf("10 크기가 n인 배열 array에서 임의의 위치 loc에 있는 정수를 삭제하는 함수 delete()를 작성하라.\n");
	printf("정수가 삭제되면 그 뒤에 있는 정수들은 한 칸씩 앞으로 이동하여야 한다.\n");
	printf("현재 배열에 들어있는 원소의 개수는 items개라고 하자. (여기서 items << n라고 가정)\n\n");

	printf("int delete(int array[], int loc) {\n");
	printf("    ...\n");
	printf("}\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("#define N 10\n\n");

	printf(
		"void delete(int array[], int loc)\n"
		"{\n"
		"    int temp = -1;\n"
		"    for (int i = loc; i < N - 1; i++)\n"
		"    {\n"
		"        temp = array[i + 1];\n"
		"        array[i] = temp;\n"
		"    }\n"
		"}\n"
	);

	printf("\n---------- 출력 예시 ----------\n\n");

	printf(
		"int array[N] = { 0, 1, 2, 3, 4, 5, };\n"
		"\n"
		"delete(array, 4);\n"
		"\n"
		"for (int i = 0; i < N; i++)\n"
		"{\n"
		"    printf(\"인덱스 %%d번째의 값 : %%d\\n\", i, array[i]);\n"
		"}\n"
	);


	printf("\n---------- 출력 결과 ----------\n\n");

	int array[N] = { 0, 1, 2, 3, 4, 5, };

	delete(array, 4);

	for (int i = 0; i < N; i++)
	{
		printf("인덱스 %d번째의 값 : %d\n", i, array[i]);
	}

	printf("\n---------- 끝 ----------\n\n");
}

void quiz11()
{
	printf("---------- 문제 ----------\n\n");

	printf("11 앞의 문제에서 구현한 delete() 함수의 시간 복잡도는?\n\n");

	printf("---------- 정답 ----------\n\n");

	printf("O(n)\n");

	printf("\n---------- 끝 ----------\n\n");
}


// Quiz 12 struct 선언부
typedef struct Quiz12
{
	char arrChar[20];
	int num1;
} Quiz12;

void quiz12()
{
	printf("---------- 문제 ----------\n\n");

	printf("12 1개의 정수와 최대 크기가 20인 문자열로 이루어진 구조체를 저장할 수 있도록 ");
	printf("동적 메모리를 할당받고 여기에 정수 100과 문자열 \"just testing\"을 저장한 다음, ");
	printf("동적 메모리를 반납하는 프로그램을 작성하라.\n\n");

	printf("---------- 정답 ----------\n\n");

	printf(
		"typedef struct Quiz12\n"
		"{\n"
		"    char arrChar[20];\n"
		"    int num1;\n"
		"} Quiz12;\n\n"

		"int main()\n"
		"{\n"
		"    Quiz12* answer;\n\n"

		"    answer = (Quiz12*)malloc(sizeof(Quiz12));\n\n"

		"    if (answer == NULL)\n"
		"    {\n"
		"        fprintf(stderr, \"메모리가 부족해서 할당할 수 없습니다.\\n\");\n"
		"        exit(1);\n"
		"    }\n\n"

		"    strcpy(answer->arrChar, \"just testing\");\n"
		"    answer->num1 = 100;\n\n"

		"    printf(\"answer -> arrChar : %%s\\nanswer -> num1 : %%d\\n\", answer->arrChar, answer->num1);\n\n"

		"    free(answer);\n\n"

		"    return 0;\n"
		"}\n"
	);

	printf("\n---------- 출력 예시 ----------\n\n");

	Quiz12* answer;

	answer = (Quiz12*)malloc(sizeof(Quiz12));

	if (answer == NULL)
	{
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	strcpy(answer->arrChar, "just testing");
	answer->num1 = 100;

	printf("answer -> arrChar : %s\n", answer->arrChar);
	printf("answer -> num1 : %d\n", answer->num1);

	free(answer);

	printf("\n---------- 끝 ----------\n\n");
}