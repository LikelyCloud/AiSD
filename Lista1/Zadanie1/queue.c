#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int top;
    int* elements;
};

struct Queue* createQueue(int size) {
    struct Queue* pt = (struct Queue*)malloc(sizeof(struct Queue));

    pt->size = size;
    pt->top = -1;
    pt->elements = (int*)malloc(sizeof(int) * size);

    return pt;
}

int queueSize(struct Queue* pt) {
    return pt->top + 1;
}

int isQueueEmpty(struct Queue* pt) {
    return queueSize(pt) == 0;
}

int isQueueFull(struct Queue* pt) {
    return queueSize(pt) == pt->size;
}

int queuePop(struct Queue* pt) {
    int result;

    if (isQueueEmpty(pt)) {
        puts("Error! Queue is empty!");
        exit(EXIT_FAILURE);
    }

    result = pt->elements[0];

    for (int i = 0; i < pt->top; ++i) {
        pt->elements[i] = pt->elements[i + 1];
    }
    --pt->top;

    return result;
}

void queuePush(struct Queue* pt, int value) {
    if (isQueueFull(pt)) {
        puts("Error! Queue is full!");
        exit(EXIT_FAILURE);
    }

    pt->elements[++pt->top] = value;
}