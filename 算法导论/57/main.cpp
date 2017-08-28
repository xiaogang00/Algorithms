#include <cstdlib>
#include <iostream>

#include "avl.h"

using namespace std;

int main(int argc, char *argv[])
{
    int data;
    struct avl_node *avl_tree=NULL;
    while(cin>>data)
    {
     insert_node(avl_tree,data);
    }
    trace_tree(avl_tree);
    system("PAUSE");
    return EXIT_SUCCESS;
}
