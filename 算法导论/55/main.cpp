#include <cstdlib>
#include <iostream>
#include <string>

#include "tree.h"

using namespace std;

int main(int argc, char *argv[])
{
    char c;
    string s;
    while(cin>>c)
    {
     s.push_back(c);
    }
    struct tree_node *b_tree=string_to_tree(s);
    trace_tree(b_tree);
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
