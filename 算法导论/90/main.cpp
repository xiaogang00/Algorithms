#include <cstdlib>
#include <iostream>
#define N 5
#define TOTAL_W 10
using namespace std;

int p[N]={6,3,5,4,6};
int w[N]={2,2,6,5,4};
int c=TOTAL_W;                    //背包总容量 
int mem[N][TOTAL_W+1];              //记录表，解决重复计算问题 
int site[N]={0};
int res_site[N]={0};
int value=0;
int res_value=0;

void init()
{
     for(int i=0;i<N;i++)
     {
      for(int j=0;j<TOTAL_W+1;j++)
      mem[i][j]=-1;
     }
}

int go(int i,int weight)
{
     if(i>=N)                    //解 
     {
      if(value>res_value)
      {
       res_value=value;
       for(int i=0;i<N;i++)
       res_site[i]=site[i];
      }
      return res_value;
     }
     
     if(mem[i][weight]==-1)   //没计算过go(i,weight)
     {
      if(w[i]<=weight)
      {
       site[i]=0;
       go(i+1,weight);     //不要她 
       int a=mem[i+1][weight];
       
       value+=p[i];
       site[i]=1;
       go(i+1,weight-w[i]); //要她 
       int b=mem[i+1][weight-w[i]];
       if(a>b)
       {
        value-=p[i];
        site[i]=0;
        mem[i][weight]=value;
       }
       else
       {
        mem[i][weight]=value;
        value-=p[i];
        site[i]=0;
       }
      }
      else
      {
       go(i+1,weight);
       mem[i][weight]=mem[i+1][weight];
      }
     } 

}

void print()
{
     int res_w=0;
     for(int i=0;i<N;i++)
     {
      if(res_site[i])
      {
       res_w+=w[i];
       cout<<w[i]<<" "<<p[i]<<endl;
      }
     }
     cout<<res_w<<" "<<res_value<<endl;
}
int main(int argc, char *argv[])
{
    init();
    go(0,c);
    print();
    system("PAUSE");
    return EXIT_SUCCESS;
}
