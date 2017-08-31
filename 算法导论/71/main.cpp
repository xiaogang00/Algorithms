#include <cstdlib>
#include <iostream>

#include "calculate.h"

using namespace std;

int main(int argc, char *argv[])
{
    init_ops();
    string s("2*(3+1)*(1+0)");
    int res=calculate(s);
    cout<<res<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
