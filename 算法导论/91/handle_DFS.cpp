#include "head.h"
#include "node.h"
#include "queue.h"
#include "makeadj.h"
#include "handle.h"

using namespace std;
/****************************************
dfs_visit传递的参数太多了，有待改进
****************************************/ 
void dfs_visit(int &time,int i,struct node* (v[]),int d[],int f[],int parent[],COLOR color[])
{
    d[i]=++time;
    color[i]=GRAY;
    struct node *p=v[i];
    while(p->next!=NULL)
    {
     p=p->next;
     if(color[p->seq]==WHITE)
     {
      parent[p->seq]=i;
      dfs_visit(time,p->seq,v,d,f,parent,color);
     }
    }
    color[i]=BLACK;
    f[i]=++time;
}
int dfs(struct node* (v[]),int d[],int f[],int parent[])
{
    COLOR color[N];
    int time=0;
    for(int i=0;i<N;i++)         //init
    {
     color[i]=WHITE;
     parent[i]=i;
     d[i]=INF;
     f[i]=INF;
    }
    for(int i=0;i<N;i++)
    {
     if(color[i]==WHITE)
     {
      dfs_visit(time,i,v,d,f,parent,color); //传递的参数有点多了 
     }
    }
    return 0; 
}

int handle_dfs(char *filename)
{
/********************************************
the data that will be handled:
    v[N] 
need to memory data:
     d[],f[],parent[]
     that are the result data
*********************************************/ 
    struct node* (v[N]);
    int d[N];
    int f[N];
    int parent[N];           //跟BFS不一样 
    input(filename,v);
    dfs(v,d,f,parent);
    print_dfs(v,parent,d,f);
    return 0;
}
/*********************************
print every elem's parent
*********************************/
void print_dfs(struct node* (v[]),int parent[],int d[],int f[])
{
    for(int i=0;i<N;i++)
    {
     cout<<v[i]->seq<<" "<<parent[v[i]->seq]<<" "<<
     d[i]<<" "<<f[i]<<endl;
    } 
}
