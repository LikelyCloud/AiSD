#include <stdio.h>
#include "queue.h"
#include "stack.h"

int main() {
    struct Queue* queue = createQueue(256);
    struct Stack* stack = createStack(256);

    printf("\nQUEUE:\n");

    for (int i = 1; i <= 100; ++i) {
        queuePush(queue, i);
        printf("Inserted %d  ", i);
    }

    printf("\n");

    for (int i = 1; i <= 100; ++i) {
        printf("Fetched %d  ", queuePop(queue));
    }

    printf("\nSTACK:\n");

    for (int i = 1; i <= 100; ++i) {
        stackPush(stack, i);
        printf("Inserted %d  ", i);
    }

    printf("\n");

    for (int i = 1; i <= 100; ++i) {
        printf("Fetched %d  ", stackPop(stack));
    }

    return 0;
}
