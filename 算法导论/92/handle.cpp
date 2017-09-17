#include "head.h"
#include "node.h"
#include "set.h"
#include "handle.h"

using namespace std;

array set_v;

int handle(char *filename)
{
     make_set();
     fstream infile(filename,fstream::in);
     string aline;
     while(getline(infile,aline))
     {
      stringstream str(aline);
      char begin,end;
      str>>begin>>end;
      cout<<begin<<" "<<end<<endl;
      if(find(begin)!=find(end))         //begin和end在两个集合中 
      {
       struct node *set1,*set2;
       if((set1=find(begin))==NULL)
       {
        return -1;
       }
       if((set2=find(end))==NULL)
       {
        return -1;
       }
       int m,n;
       for(int i=0;i<N;i++)
       {
        if(set1==set_v[i])
        m=i;
        if(set2==set_v[i])
        n=i;
       }
       un(set_v[m],set_v[n]);    //传进去的是引用 
      }
     }
     infile.close();
     return 0;
}
