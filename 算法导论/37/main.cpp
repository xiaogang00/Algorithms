#include <cstdlib>
#include <iostream>

#include "list_gurd.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct list list;
    list.head=NULL;
    list.tail=NULL;
    int data;
    while(cin>>data)
    {
     add_list(&list,data);
    }
    trace_list(&list);
    system("PAUSE");
    return EXIT_SUCCESS;
}
