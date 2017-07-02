#include <cstdlib>
#include <iostream>
#include <vector>

#include "queue.h"

using namespace std;
void input_v(vector<int> &v)
{
     int data;
     while(cin>>data)
     {
      v.push_back(data);
     }
}

int main(int argc, char *argv[])
{
    struct queue queue;
    queue.head=queue.tail=0;
    for(int i=0;i<20;++i)
    {
     enqueue(&queue,i);
    }
    enqueue(&queue,111);
    int data=dequeue(&queue);
    cout<<data<<endl;
    enqueue(&queue,111);
    enqueue(&queue,111);
    data=dequeue(&queue);
    cout<<data<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
