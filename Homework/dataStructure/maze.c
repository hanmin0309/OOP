#include "stack.h"
#define MAZE_SIZE 6

char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'2', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '1', '1', '0', '0', '3'},
    {'1', '1', '1', '0', '1', '1'},
    {'1', '1', '1', '1', '1', '1'}
};

void push_loc(stack* s, int r, int c)
{
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
        return;

    if (map[r][c] != '1' && map[r][c] != '.')
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void randering()
{
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            switch (map[r][c]) {
            case '0': printf("□");
                break;

            case '1': printf("■");
                break;

            case '2': printf("·");
                break;

            case '3': printf("★");
                break;

            case '4': printf("※");
                break;

            default: printf("%c", map[r][c]);
                break;
            }
        }
        printf("\n");
    }

}

void main()
{
    element here = { 1, 0 }; // {y, x}, x y 헷깔리지 말것.    

    stack s;

    init_stack(&s);

    while (map[here.r][here.c] != '3')
    {
        /* code */
        map[here.r][here.c] = '4';
        push_loc(&s, here.r - 1, here.c);
        push_loc(&s, here.r + 1, here.c);
        push_loc(&s, here.r, here.c - 1);
        push_loc(&s, here.r, here.c + 1);

        if (is_empty(&s))
        {
            printf("실패\n");
            return;
        }

        else
            here = pop(&s);

        randering();

        printf("\n계속 출력하려면, 아무키나 입력하세요.\n");
        getchar();
         system("cls");
        map[here.r][here.c] = '2';
    }

    printf("성공");
}