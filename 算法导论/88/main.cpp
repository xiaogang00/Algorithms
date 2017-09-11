#include <cstdlib>
#include <iostream>
#define N 4                  //结点数 
#define MAX 1000
using namespace std;

int node_list[N]={0,1,2,3};             //记录考查结点的排列 
int net[N][N]={{0}};
int res_node[N]={0};
int cost_res=MAX;
int cost=0;
void init_net()
{
     net[0][1]=30;
     net[0][2]=6;
     net[0][3]=4;
     net[1][0]=30;
     net[1][2]=5;
     net[1][3]=10;
     net[2][0]=6;
     net[2][1]=5;
     net[2][3]=20;
     net[3][0]=4;
     net[3][1]=10;
     net[3][2]=20;
}

void swap(int &a,int &b)
{
     int tmp=a;
     a=b;
     b=tmp;
}
void print()
{
     cout<<cost_res<<endl;
     for(int i=0;i<N;i++)
     cout<<res_node[i]<<" ";
     cout<<endl;
}
void go(int i)                 //从1开始（1，2，3） 
{
     if(i>=N)
     {
      if(net[0][node_list[N-1]]!=0)    //0结点 －－－node_list[N-1]结点有连接 
      {
       cost+=net[0][node_list[N-1]];
       if(cost<cost_res)
       {
        cost_res=cost;
        for(int i=0;i<N;i++)
        {
         res_node[i]=node_list[i];
        }
       } 
      } 
      return; 
     }
     
     for(int j=i;j<N;j++)
     {
      swap(node_list[i],node_list[j]);
      if(net[node_list[i-1]][node_list[i]]!=0)  //i结点与i-1结点有连接 ，添加它 
      {
       cost+=net[node_list[i-1]][node_list[i]]; 
       go(i+1);   
       cost-=net[node_list[i-1]][node_list[i]];           
      } 
      swap(node_list[i],node_list[j]);
     }
}
int main(int argc, char *argv[])
{
    init_net();
    go(1);
    print();
    system("PAUSE");
    return EXIT_SUCCESS;
}
