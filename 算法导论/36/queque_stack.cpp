#include <cstdlib>
#include <iostream>

#include "queque_stack.h"

using namespace std;

void enqueue(struct queue *queue,int elem)
{
     if(queue->head==(queue->tail+1)%LEN)
     {
      cout<<"full"<<endl;
      return;
     }
     queue->array[(++queue->tail)%LEN]=elem;
}
int dequeue(struct queue *queue)
{
    if(queue->head==queue->tail)
    {
     return -1;
    }
    return queue->array[(++queue->head)%LEN];
}

void push(struct stack *stack,int elem)
{
     enqueue(&(stack->queuea),elem);
}

int pop(struct stack *stack)
{
    if(stack->queuea.head==stack->queuea.tail)
    {
     cout<<"empty"<<endl;
     return -1;
    }
    int data;
    int size=0;
    while((data=dequeue(&(stack->queuea)))!=-1)
    {
     ++size;
     enqueue(&(stack->queueb),data);
    }
    while(size>1)
    {
     --size;
     data=dequeue(&(stack->queueb));
     enqueue(&(stack->queuea),data);
    }
    return dequeue(&(stack->queueb));
}
