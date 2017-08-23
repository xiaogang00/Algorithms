#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[])
{
    int data;
    struct tree_node *b_tree=NULL;
    while(cin>>data)
    {
     insert_node(b_tree,data);
    } 
    l_trace_tree(b_tree);
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
