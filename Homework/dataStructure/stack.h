#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
// typedef int element; // maze를 제외한 나머지 파일에 사용

typedef struct point // maze.c 전용
{
    int r;
    int c;
}element;

typedef struct stackType{
    element data[MAX_STACK_SIZE];
    int top;
}stack;

void init_stack(stack* s)
{
    s->top=-1;
}

bool is_full(stack* s)
{
    if(s->top==MAX_STACK_SIZE-1) return true;
    else return false;
}

void push(stack* s, element item)
{
    if(!is_full(s))
       s->data[++s->top]=item;
}

bool is_empty(stack* s)
{
    if(s->top==-1) return true;
    else return false;
}

element pop(stack* s)
{
    if(!is_empty(s))
       return s->data[s->top--];
}
