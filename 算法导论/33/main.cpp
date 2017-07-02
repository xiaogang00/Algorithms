#include <cstdlib>
#include <iostream>

#include "stack.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct stack stack;
    stack.top=-1;
    for(int i=0;i<LEN;++i)
    {
     push(&stack,i);
    }
    push(&stack,100);
    for(int i=0;i<=LEN;++i)
    {
     cout<<pop(&stack)<<" ";
    }
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
