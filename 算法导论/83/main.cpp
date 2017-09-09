#include <cstdlib>
#include <iostream>

#define N 8
#define M 3

using namespace std;
    int step=0;
int array[N];
int site[M];
void fuzhi()
{
     for(int i=0;i<N;i++)
     {
      array[i]=i+1;
     }
}
void output()
{
     for(int i=0;i<M;i++)
     cout<<site[i]<<" ";
     cout<<endl;
}
void go(int start,int end,int m)
{
     if(m==0)
     {
       step++;
       output();
       return;
      }
     if(start>end)
     {
      return;
     }
     for(int i=start;i<=end;i++)
     {
      site[M-m]=i;
      go(i+1,end,m-1);
     }
}
int main(int argc, char *argv[])
{

    go(0,N-1,M);
    cout<<step<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
