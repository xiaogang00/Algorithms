#include <cstdlib>
#include <iostream>

#include "stack.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct queue queue;
    queue.stacka.top=-1;
    queue.stackb.top=-1;
    
    for(int i=0;i<LEN;++i)
    {
     enqueue(&queue,i);
    }
    enqueue(&queue,100);
    cout<<dequeue(&queue)<<endl;
    cout<<dequeue(&queue)<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
