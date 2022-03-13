#ifndef ZADANIE1_QUEUE_H
#define ZADANIE1_QUEUE_H

struct Queue;
struct Queue* createQueue(int);
int queueSize(struct Queue*);
int isQueueEmpty(struct Queue*);
int isQueueFull(struct Queue*);
int queuePop(struct Queue*);
void queuePush(struct Queue*, int);

#endif //ZADANIE1_QUEUE_H
