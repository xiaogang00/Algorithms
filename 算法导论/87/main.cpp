#include <cstdlib>
#include <iostream>
#define N 4
using namespace std;

int weight[N]={3,5,2,1};
int price[N]={9,10,7,4};
int total_w=7;
int res[N]={0};
int site[N]={0};
int total_p=0;
int res_p=0;
int bug=total_w;

void go(int i)
{
     if(i>=N)               //已到解空间树的叶节点 
     {
      if(total_p>res_p)
      {
       for(int j=0;j<N;j++)
       res[j]=site[j];
       res_p=total_p;
      }
      return;
     }     
     if(weight[i]<=bug)
     {
      bug-=weight[i];
      site[i]=1;
      total_p+=price[i]; 
      go(i+1);               //site[i]=1  装上这个                  
      bug+=weight[i];
      site[i]=0;
      total_p-=price[i];
      go(i+1);               //site[i]=0  不装它 
     }
     else
     {
      site[i]=0;
      go(i+1);                //site[i]=0 不装它 
     }
}
void print()
{
     cout<<res_p<<endl;
     for(int i=0;i<N;i++)
     {
      if(res[i])
      cout<<weight[i]<<" "<<price[i]<<endl;
     }
}
int main(int argc, char *argv[])
{
    go(0);
    print();
    system("PAUSE");
    return EXIT_SUCCESS;
}
