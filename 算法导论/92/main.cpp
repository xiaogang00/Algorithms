#include "head.h"
#include "node.h"
#include "set.h"
#include "handle.h"

using namespace std;

int main(int argc, char *argv[])
{
    extern array set_v;
    int count=0;
    if(handle("e:\\in2.txt")==-1)
    {
     cout<<"error"<<endl;
    }
    else
    {
     for(int i=0;i<N;i++)
     {
      if(set_v[i]!=NULL)
      count++;
     }
     cout<<count<<endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
