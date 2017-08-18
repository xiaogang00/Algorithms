#include <cstdlib>
#include <iostream>

#include "stack.h"

using namespace std;

void push(struct stack *stack,int elem)
{
     if(stack->top==LEN-1)
     {
      cout<<"full"<<endl;
      return;
     }
     stack->array[++stack->top]=elem;
}
int pop(struct stack *stack)
{
    if(stack->top==-1)
    {
     return -1;
    }
    return stack->array[stack->top--];
}
void enqueue(struct queue *queue,int elem)
{
     push(&(queue->stacka),elem);
}

int dequeue(struct queue *queue)
{       
        int data;
        
       while((data=pop(&(queue->stacka)))!=-1)
       {
        push(&(queue->stackb),data);
       }
       int ret=pop(&(queue->stackb));
       while((data=pop(&(queue->stackb)))!=-1)
       {
        push(&(queue->stacka),data);
       }
       return ret;
}
