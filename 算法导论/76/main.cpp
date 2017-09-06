#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

#define INF 10000

using namespace std;

int fig[6][6]={{0}};
int node[2][6]={{0,1,2,3,4,5},
                {0,INF,INF,INF,INF,INF}};
vector<int> visiting;
vector<int> will_visit;
vector<int> trace;

void init_fig()
{
     fig[0][1]=2;
     fig[0][2]=1;
     fig[1][2]=3;
     fig[1][3]=7;
     fig[2][3]=1;
     fig[2][5]=8;
     fig[3][4]=2;
     fig[4][5]=1;
}
void insert_w_visit(int j)
{
     for(vector<int>::iterator iter=will_visit.begin();iter!=will_visit.end();iter++)
     {
      if(*iter==j)
      return;
     }
     will_visit.push_back(j);
}
void visit()
{
     if(visiting.empty())
     {
      return;
     }
     for(vector<int>::iterator iter=visiting.begin();iter!=visiting.end();iter++)
     {
       for(int j=0;j<6;j++)
       {
         if(fig[*iter][j]!=0)
         {
         int price=node[1][*iter]+fig[*iter][j];
         if(price<node[1][j])
         node[1][j]=price;
         insert_w_visit(j);
         }
       }
     }
     visiting=will_visit;
     will_visit.clear();
     return visit();
}
void output_t()
{
     for(vector<int>::reverse_iterator r_iter=trace.rbegin();r_iter!=trace.rend();r_iter++)
     cout<<setw(2)<<*r_iter;
     cout<<endl;
}
void trave()
{
     int j=5;
     while(j!=0)
     {
      for(int i=0;i<6;i++)
      {
       if(fig[i][j]!=0&&node[1][i]+fig[i][j]==node[1][j])
       {
        trace.push_back(i);
        j=i;
        break;
       }
      }
     }
     output_t();
}

int main(int argc, char *argv[])
{
    visiting.push_back(0);
    trace.push_back(5);
    init_fig();
    visit();
    trave();
    cout<<node[1][5]<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
