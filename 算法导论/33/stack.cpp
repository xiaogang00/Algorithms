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
     cout<<"empty"<<endl;
     return -1;
    }
    return stack->array[stack->top--];
}
