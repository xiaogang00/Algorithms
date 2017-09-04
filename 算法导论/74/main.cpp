#include <cstdlib>
#include <iostream>
#include <iomanip>
#define  N 5

using namespace std;

int starti=2;
int startj=2;

int chess[N][N]={{0}};
int stepto[2][8]={{-2,-1,1,2,2,1,-1,-2},                   //row
                  {-1,-2,-2,-1,1,2,2,1}};                  //line
int step=0;
void output()
{
     for(int i=0;i<N;i++)
     {
      for(int j=0;j<N;j++)
      cout<<setw(4)<<chess[i][j];
      cout<<endl;
     }  
     cout<<endl;
     cout<<endl;  
}
void go(int i,int j)
{
     chess[i][j]=step;
    if(step==N*N)
    {
     output();
     return;
    }
    for(int k=0;k<8;k++)
    {
     if(i+stepto[0][k]>=0&&i+stepto[0][k]<N&&
        j+stepto[1][k]>=0&&j+stepto[1][k]<N&&
        chess[i+stepto[0][k]][j+stepto[1][k]]==0)
        {
         step++;
         go(i+stepto[0][k],j+stepto[1][k]);
         chess[i+stepto[0][k]][j+stepto[1][k]]=0;
         step--;
        }
    }
}
int main(int argc, char *argv[])
{
    step=1;
    go(starti,startj);
    system("PAUSE");
    return EXIT_SUCCESS;
}
