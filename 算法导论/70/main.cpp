#include <cstdlib>
#include <iostream>
#include <map>

#define HASTRAVE 2
#define HASBACK 3

using namespace std;

int starti=1;
int startj=1;
int endi=9;
int endj=16;
int maze[11][18]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1},
    {1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,1},
    {1,1,0,0,1,0,1,1,0,1,1,1,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1},
    {1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,1,0,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void output()
{
     for(int i=0;i<11;i++)
     {
      for(int j=0;j<18;j++)
      {
      if(maze[i][j]==3)
      maze[i][j]=0;
      cout<<maze[i][j]<<" ";
      }
      cout<<endl;
     }
}
int go(int &i,int &j)
{
/************go forword***************/
     if(maze[i][j-1]==0)              //left
     {
      j=j-1;
      maze[i][j]=2;
      return 2;
     }
     if(maze[i][j+1]==0)              //right
     {
      j=j+1;
      maze[i][j]=2;      
      return 2;
     }
     if(maze[i-1][j]==0)              //up
     {
      i=i-1;
      maze[i][j]=2;
      return 2;
     }
     if(maze[i+1][j]==0)              //down
     {
      i=i+1;
      maze[i][j]=2;
      return 2;
     }
     
/******************go back************/     
     
     if(maze[i][j-1]==2)              //left
     {
      maze[i][j]=3;
      j=j-1;
      return 3;
     }
     if(maze[i][j+1]==2)              //right
     {
      maze[i][j]=3;
      j=j+1;    
      return 3;
     }
     if(maze[i-1][j]==2)              //up
     {
      maze[i][j]=3;
      i=i-1;
      return 3;
     }
     if(maze[i+1][j]==2)              //down
     {
      maze[i][j]=3;
      i=i+1;
      return 3;
     }
/*********over***********/
     return 0;
}
int search(int i,int j)
{
     int flag=go(i,j);
     if(i==endi&&j==endj)
     {
      output();
      return 1;
     }
     if(flag==0)
     {
      cout<<"not find"<<endl;
      return 0;
     }
     return search(i,j);
}
int main(int argc, char *argv[])
{
    maze[starti][startj]=2;
    search(starti,startj);
    system("PAUSE");
    return EXIT_SUCCESS;
}
