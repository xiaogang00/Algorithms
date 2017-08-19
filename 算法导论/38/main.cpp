#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct node list;
    list.next=NULL;
    int data;
    while(cin>>data)
    {
     add_list(&list,data);
    }
    reverse_list(&list);
    print_list(&list);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
