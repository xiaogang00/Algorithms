#include <cstdlib>
#include <iostream>
#include <iomanip>

#define N 4

using namespace std;

int chess[N][N]={{0}};

int incompletei=0;
int incompletej=0;
int step=0;
//int fillblock[2][4]={{0}};          在这定义就出错了 

void output()
{
     for(int i=0;i<N;i++)
     {
      for(int j=0;j<N;j++)
      {
       cout<<setw(4)<<chess[i][j];
      }
      cout<<endl;
     }
     cout<<endl;
     cout<<endl;
}
void fill(int size,int i,int j,int incmpi,int incmpj)
{
     if(size==1)
     {
      if((N*N-1)/3==step)
      {
      output();
      }
      return;
     }
     int fillblock[2][4];//={{0}};                     //在这定义就OK 
     if(incmpi<i+size/2&&incmpj<j+size/2)        //leftup
     {
      fillblock[0][0]=incmpi;
      fillblock[1][0]=incmpj;
      fillblock[0][1]=i+size/2;
      fillblock[1][1]=j+size/2-1;
      fillblock[0][2]=i+size/2;
      fillblock[1][2]=j+size/2;
      fillblock[0][3]=i+size/2-1;
      fillblock[1][3]=j+size/2;
     }
     if(incmpi>=i+size/2&&incmpj<j+size/2)       //leftdown       
     {
      fillblock[0][0]=i+size/2-1;
      fillblock[1][0]=j+size/2-1;
      fillblock[0][1]=incmpi;
      fillblock[1][1]=incmpj;
      fillblock[0][2]=i+size/2;
      fillblock[1][2]=j+size/2;
      fillblock[0][3]=i+size/2-1;
      fillblock[1][3]=j+size/2;
     }
     if(incmpi>=i+size/2&&incmpj>=j+size/2)      //rightdown
     {
      fillblock[0][0]=i+size/2-1;
      fillblock[1][0]=j+size/2-1;
      fillblock[0][1]=i+size/2;
      fillblock[1][1]=j+size/2-1;
      fillblock[0][2]=incmpi;
      fillblock[1][2]=incmpj;
      fillblock[0][3]=i+size/2-1;
      fillblock[1][3]=j+size/2;
     }
     if(incmpi<i+size/2&&incmpj>=j+size/2)       //rightup
     {
      fillblock[0][0]=i+size/2-1;
      fillblock[1][0]=j+size/2-1;
      fillblock[0][1]=i+size/2;
      fillblock[1][1]=j+size/2-1;
      fillblock[0][2]=i+size/2;
      fillblock[1][2]=j+size/2;
      fillblock[0][3]=incmpi;
      fillblock[1][3]=incmpj;
     }
     step++;
     for(int n=0;n<4;n++)
     {
       if(fillblock[0][n]!=incmpi||fillblock[1][n]!=incmpj)     //
       {
        chess[fillblock[0][n]][fillblock[1][n]]=step;
       }
     }
     fill(size/2,i,j,fillblock[0][0],fillblock[1][0]);
     fill(size/2,i+size/2,j,fillblock[0][1],fillblock[1][1]);
     fill(size/2,i+size/2,j+size/2,fillblock[0][2],fillblock[1][2]);
     fill(size/2,i,j+size/2,fillblock[0][3],fillblock[1][3]);
}
int main(int argc, char *argv[])
{
    chess[incompletei][incompletej]=-1;
    fill(N,0,0,incompletei,incompletej);
    system("PAUSE");
    return EXIT_SUCCESS;
}
