#include <cstdlib>
#include <iostream>
#include <iomanip>

#define MAX 100

using namespace std;
void prime(int max,int res[],int& size)
{
     bool flag[max+1];
     memset(flag,true,sizeof(flag));
     for(int i=2;i<=max;i++)
     {
      for(int j=i*2;j<=max;j+=i)
      {
       if(flag[j]==true)
       flag[j]=false;
      }
     }     
     for(int i=1;i<=max;i++)
     {
      if(flag[i]==true)
      res[size++]=i;
     }
}
void output(const int res[],int size)
{
     for(int i=0;i<size;i++)
     {
     cout<<setw(4)<<res[i];
     if((i+1)%8==0)
     cout<<endl;
     }
     cout<<endl;
}
int main(int argc, char *argv[])
{
    int size=0;
    int res[MAX];
    prime(MAX,res,size);
    output(res,size);
    system("PAUSE");
    return EXIT_SUCCESS;
}
