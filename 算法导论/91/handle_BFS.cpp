#include "head.h"
#include "node.h"
#include "queue.h"
#include "makeadj.h"
#include "handle.h"

using namespace std;

int bfs(int s,struct node* (v[N]),struct node* (parent[]),int distance[])
{
     COLOR color[N];                //记录访问情况 
     struct queue queue;
     init_queue(queue);             //定义队列 
     for(int i=0;i<N;i++)           //初始化 
     {
       parent[i]=NULL;
       distance[i]=INF;
       color[i]=WHITE; 
     }
     parent[s]=NULL;
     distance[s]=0;
     color[s]=GRAY;
     enqueue(queue,v[s]); 
     while(!empty(queue))
     {
      struct node *u=dequeue(queue);
      if(u==NULL)
      {
       cout<<"dequeue error"<<endl;
       return -1;
      }
      struct node *p=v[u->seq];
      while(p->next!=NULL)
      {
       p=p->next;
       if(color[p->seq]==WHITE)
       {
        color[p->seq]=GRAY;
        distance[p->seq]=distance[u->seq]+1;
        parent[p->seq]=u;
        enqueue(queue,p);
       }
      }
      color[u->seq]=BLACK;
     }
     return 0; 
}
int handle_bfs(char *filename,int s)
{
     struct node* (v[N]);   
     struct node* (parent[N]);         //父节点(存储的是指针，要注意)
                                       //存seq也可以 
     int distance[N];                  //记录距离 
     input(filename,v);              
     if(bfs(s,v,parent,distance)==-1)
     {
      cout<<"handle error"<<endl;
      return -1;
     }
     print(parent,s,3);               //3是测试数据 
     return 0;
}

void print(struct node* (parent[]),int s,int v)
{
     if(s==v)
     {
      cout<<s<<" ";
      return;
     }
     if(parent[v]==NULL)
     {
      cout<<"no path"<<endl;
      return ;
     }
     print(parent,s,parent[v]->seq);
     cout<<v<<" ";
}
