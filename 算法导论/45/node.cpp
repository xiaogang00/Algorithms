#include <cstdlib>
#include <iostream>

#include "node.h"

using namespace std;
void init(struct queue*& queue)
{
     queue->head=queue->tail=new struct node;
     queue->head->next=NULL;
}
void enqueue(struct node *queue,int elem)
{
     struct node *p=new struct node;
     p->data=elem;
     p->next=queue->next;
     queue->next=p;
     queue->tail=p;
}

struct node& dequeue(struct node *queue)
{
       if(queue->head!=queue->tail)
       {
        queue->tail=
       }
}
