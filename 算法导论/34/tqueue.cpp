#include <cstdlib>
#include <iostream>

#include "tqueue.h"

using namespace std;

void enqueue_head(struct tqueue *tqueue,int elem)
{
     if(tqueue->head==(tqueue->tail+1)%LEN)
     {
      cout<<"full"<<endl;
      return;
     }
     tqueue->array[tqueue->head]=elem;
     tqueue->head=(--tqueue->head+LEN)%LEN;
}
void enqueue_tail(struct tqueue *tqueue,int elem)
{
     if(tqueue->head==(tqueue->tail+1)%LEN)
     {
      cout<<"full"<<endl;
      return;
     }
     tqueue->array[++tqueue->tail]=elem;
}

int dequeue_head(struct tqueue *tqueue)
{
    if(tqueue->head==tqueue->tail)
    {
     cout<<"empty"<<endl;
     return -1;
    }
    return tqueue->array[(++tqueue->head)%LEN];
}

int dequeue_tail(struct tqueue *tqueue)
{
    if(tqueue->head==tqueue->tail)
    {
     cout<<"empty"<<endl;
     return -1;
    }
    int data=tqueue->array[tqueue->tail];
    tqueue->tail=(--tqueue->tail+LEN)%LEN;
    return data;
}
