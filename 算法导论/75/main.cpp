#include <cstdlib>
#include <iostream>
#include <stack>

#define N 9
#define M 5

using namespace std;
struct node
{
       int i;
       int j;
};

int starti=0;
int startj=0;
int step[2][4]={{1,1,2,2},
                {2,-2,1,-1}};
stack<struct node> site;

void output()
{
     stack<struct node> siteprint(site);
     while(!siteprint.empty())
     {
      cout<<"("<<(siteprint.top()).i<<" "<<(siteprint.top()).j<<")"<<" ";
      siteprint.pop();
      }
      cout<<endl;
}
void go(int i,int j)
{
     int k;
     struct node step_node;
     step_node.i=i;
     step_node.j=j;
     site.push(step_node);
     if(i==N-1&&j==M-1)
     {
      output();
      return;
     }
     for(k=0;k<4;k++)
     {
      if(i+step[0][k]>=0&&i+step[0][k]<N&&j+step[1][k]>=0&&j+step[1][k]<M)
      {
       go(i+step[0][k],j+step[1][k]);
       site.pop();
      }
     }
}
int main(int argc, char *argv[])
{
    go(starti,startj);
    system("PAUSE");
    return EXIT_SUCCESS;
}
