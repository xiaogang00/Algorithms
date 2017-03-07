#include <cstdlib>
#include <iostream>

#include "class.h"

using namespace std;

int main(int argc, char *argv[])
{
    struct node *p1=new struct node;
    struct node *p2=new struct node;
    create_ploy(p1,p2);
    input_ploy(p1,p2);
    add_ploy(p1,p2);
    print_ploy(p2);
    system("PAUSE");
    return EXIT_SUCCESS;
}
