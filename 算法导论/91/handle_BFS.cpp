#include "head.h"
#include "node.h"
#include "queue.h"
#include "makeadj.h"
#include "handle.h"

using namespace std;

int bfs(int s,struct node* (v[N]),struct node* (parent[]),int distance[])
{
     COLOR color[N];                //��¼������� 
     struct queue queue;
     init_queue(queue);             //������� 
     for(int i=0;i<N;i++)           //��ʼ�� 
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
     struct node* (parent[N]);         //���ڵ�(�洢����ָ�룬Ҫע��)
                                       //��seqҲ���� 
     int distance[N];                  //��¼���� 
     input(filename,v);              
     if(bfs(s,v,parent,distance)==-1)
     {
      cout<<"handle error"<<endl;
      return -1;
     }
     print(parent,s,3);               //3�ǲ������� 
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
