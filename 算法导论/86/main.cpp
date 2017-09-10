#include <cstdlib>
#include <iostream>

using namespace std;
int res_max=1;
int net[10]={8,7,4,2,5,1,9,3,10,6};
int res[10];
int site=0;
void init()
{
     for(int i=0;i<10;i++)
     {
      res[i]=1;
     }
}
void go()
{
     for(int i=0;i<10;i++)
     {
      int max=1;
      for(int j=0;j<i;j++)
      {
       if(net[i]>net[j])
       {
        if(max<res[j]+1)
        max=res[j]+1;
       }
      }
      res[i]=max;
      if(max>res_max)
      {
       res_max=max;              
       site=i;
      }
     }
}
void trace()
{
     int mem=site;
     for(int i=9;i>=0;i--)
     {
      if(net[mem]>net[i]&&res[i]==res[mem]-1)
      {
       cout<<mem<<" "<<net[mem]<<endl;
       mem=i;
      }
     }
}
int main(int argc, char *argv[])
{
    init();
    go();
    cout<<res_max<<endl;
    trace();
    system("PAUSE");
    return EXIT_SUCCESS;
}
