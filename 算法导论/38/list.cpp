#include <iostream>

#include "list.h"

using namespace std;

void add_list(struct node *list,int elem)
{
     struct node *p=new struct node;
     p->data=elem;
     p->next=list->next;
     list->next=p;
}

void reverse_list(struct node *list)
{
     if(list->next!=NULL)
     {
      struct node *p=list->next;
      while(p->next!=NULL)
      {
       struct node *q;
       q=p->next;
       p->next=p->next->next;
       q->next=list->next;
       list->next=q;
      }
     }
}

void print_list(struct node *list)
{
     struct node *p=list;
     while(p->next!=NULL)
     {
      p=p->next;
      cout<<p->data<<" ";
     }
}
