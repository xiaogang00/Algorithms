#include <cstdlib>
#include <iostream>

#include "node.h"



using namespace std;

void init(array &array)
{
     for(int i=0;i<LEN-1;++i)
     {
      array[i].next=i+1;
     }
     array[LEN-1].next=0;
     for(int i=1;i<LEN;++i)
     {
      array[i].prev=i-1;
     }
     array[0].prev=LEN-1;
}
int malloc_int(array &array)
{
    if(array[0].next!=0)
    {
     int m_int=array[0].next;
     array[0].next=array[m_int].next;
     array[array[m_int].next].prev=0;
     return m_int;
    }
    else
    {
     cout<<"no free space!"<<endl;
     return -1;   
    }
}

void free_int(array &array,int i)
{
     cout<<array[i].key<<endl;
     array[i].next=array[0].next;
     array[i].prev=0;
     array[array[0].next].prev=i;
     array[0].next=i;
}

