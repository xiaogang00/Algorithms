#include <cstdlib>
#include <iostream>

#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{
    array array;
    void init(array &array);
    struct node head;
    head.next=0;
    for(int i=0;i<30;++i)
    {
     int u=malloc_int(array);
     if(u==-1)
     exit(1);
     else
     {     
      array[u].key=i;
     }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
