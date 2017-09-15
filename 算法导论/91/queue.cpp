#include "head.h"
#include "node.h"
#include "queue.h"

using namespace std;

/*****************************
let head be empty
let tail fill data
the elem is point
******************************/
void init_queue(struct queue &queue)                   
{
     queue.head=0;
     queue.tail=0;
}
struct node* enqueue(struct queue &queue,struct node* p)
{
    if((queue.tail+1)%QUEUE_MAX==queue.head)
    {
     cout<<"queue is full"<<endl;
     return NULL;
    }
    queue.array_q[(queue.tail+1)%QUEUE_MAX]=p;
    queue.tail=(queue.tail+1)%QUEUE_MAX;
    return p;
}
struct node* dequeue(struct queue &queue)
{
       if(queue.head==queue.tail)
       {
        cout<<"queue is empty"<<endl;
        return NULL;
       }
       struct node *p=queue.array_q[(queue.head+1)%QUEUE_MAX];
       queue.head=(queue.head+1)%QUEUE_MAX;
       return p;
}
int empty(struct queue queue)
{
    if(queue.head==queue.tail)
    return 1;
    return 0;
}
