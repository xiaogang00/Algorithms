#include <cstdlib>
#include <iostream>

#include "b_tree.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct tree_node* b_tree=NULL;
    int data;
    while(cin>>data)
    {
     insert_node(b_tree,data);
    }
    trace_tree(b_tree);
    cout<<endl;
    delete_node(b_tree,5);
    trace_tree(b_tree);
    system("PAUSE");
    return EXIT_SUCCESS;
}
