#include <cstdlib>
#include <iostream>

#include "tqueue.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct tqueue tqueue;
    tqueue.head=tqueue.tail=0;
    enqueue_head(&tqueue,10);
    enqueue_tail(&tqueue,11);
    cout<<dequeue_head(&tqueue)<<" ";
    cout<<dequeue_head(&tqueue);
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
