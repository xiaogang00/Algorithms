#include <cstdlib>
#include <iostream>

#include "list_gurd.h"

using namespace std;

void add_list(struct list *list,int elem)
{
     struct node *p=new struct node;
     p->data=elem;
     if(list->head==NULL)
     {
      list->head=list->tail=p;
     }
     else
     {
      list->tail->next=p;
      p->next=NULL;
      list->tail=p;
     }
}

void trace_list(struct list *list)
{
     if(list->head!=NULL)
     {
      struct node *p=list->head;
      while(p!=NULL)
      {
       cout<<p->data<<" ";
       p=p->next;
      }
     }
}
