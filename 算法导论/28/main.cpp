#include <cstdlib>
#include <iostream>
#include <vector>

#include "node.h"
 
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    sort(v);
    print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
