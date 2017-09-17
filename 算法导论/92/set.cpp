#include "head.h"
#include "node.h"
#include "set.h"

using namespace std;

//array set_v;

void make_set()
{
    for(int i=0;i<N;i++)
    {
     set_v[i]=new struct node;
     set_v[i]->ch='a'+i;
     cout<<set_v[i]->ch<<endl;
     set_v[i]->next=NULL;
    }
}
struct node* find(char c)
{
       for(int i=0;i<N;i++)
       {
        if(set_v[i]!=NULL)
        {
         p_node p=set_v[i];
         while(p!=NULL)
         {
          if(p->ch==c)
          {
           return set_v[i];
          }
          p=p->next;
         }
        }
       }
       return NULL;
}

struct node* un(p_node &set1,p_node &set2)       //必须是引用 
{
       p_node p=set1;
       while(p->next!=NULL)
       {
        p=p->next;
       }
       p->next=set2;
       set2=NULL;        // 
       return set1;
}
