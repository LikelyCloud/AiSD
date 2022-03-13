#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int* elements;
};

struct Stack* createStack(int size) {
    struct Stack* pt = (struct Stack*)malloc(sizeof(struct Stack));

    pt->size = size;
    pt->top = -1;
    pt->elements = (int*)malloc(sizeof(int) * size);

    return pt;
}

int stackSize(struct Stack* pt) {
    return pt->top + 1;
}

int isStackEmpty(struct Stack* pt) {
    return stackSize(pt) == 0;
}

int isStackFull(struct Stack* pt) {
    return stackSize(pt) == pt->size;
}

int stackPop(struct Stack* pt) {
    if (isStackEmpty(pt)) {
        puts("Error! Stack is empty!");
        exit(EXIT_FAILURE);
    }

    return pt->elements[pt->top--];
}

void stackPush(struct Stack* pt, int value) {
    if (isStackFull(pt)) {
        puts("Error! Stack is full!");
        exit(EXIT_FAILURE);
    }

    pt->elements[++pt->top] = value;
}