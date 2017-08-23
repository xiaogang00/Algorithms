#include <cstdlib>
#include <iostream>
#include <string>

#include "tree.h"

using namespace std;

int main(int argc, char *argv[])
{
    string str;
    struct tree_node *b_tree=NULL;
    init(b_tree);
    while(cin>>str)
    {
     insert_node(b_tree,str);
    }
    trace_tree(b_tree);
    system("PAUSE");
    return EXIT_SUCCESS;
}
