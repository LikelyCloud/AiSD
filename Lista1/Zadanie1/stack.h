#ifndef ZADANIE1_STACK_H
#define ZADANIE1_STACK_H

struct Stack;
struct Stack* createStack(int);
int stackSize(struct Stack*);
int isStackEmpty(struct Stack*);
int isStackFull(struct Stack*);
int stackPop(struct Stack*);
void stackPush(struct Stack*, int);

#endif //ZADANIE1_STACK_H
