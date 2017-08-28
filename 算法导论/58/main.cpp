#include <cstdlib>
#include <iostream>

#include "treap.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct treap_node *treap=NULL;
    int key,p;
    while(cin>>key>>p)
    {
     insert_node(treap,key,p);
    }
    trace_tree(treap);
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
