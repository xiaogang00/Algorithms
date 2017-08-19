#include <cstdlib>
#include <iostream>

#include "queque_stack.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct stack stack;
    stack.queuea.head=stack.queuea.tail=0;
    stack.queueb.head=stack.queueb.tail=0;
    for(int i=0;i<LEN-1;++i)
    {
     push(&stack,i);
    }
    int data;
    data=pop(&stack);
    cout<<data<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
