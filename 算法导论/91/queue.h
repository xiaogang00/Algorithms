#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
struct queue
{
       struct node* (array_q[QUEUE_MAX]);
       int head;
       int tail;
};
void init_queue(struct queue &queue);
struct node* enqueue(struct queue &queue,struct node* p);
struct node* dequeue(struct queue &queue);
int empty(struct queue queue);
#endif
