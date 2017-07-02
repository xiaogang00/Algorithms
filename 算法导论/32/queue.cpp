#include <cstdlib>
#include <iostream>

#include "queue.h"

using namespace std;

void enqueue(struct queue *queue,int elem)
{
     if(queue->head==(queue->tail+1)%LEN)
     {
      cout<<"full"<<endl;
      return;
     }
     queue->a[(++queue->tail)%LEN]=elem;
}
int dequeue(struct queue *queue)
{
    if(queue->head==queue->tail)
    {
     cout<<"empty"<<endl;
     return -1;
    }
    return queue->a[(++queue->head)%LEN];
}
