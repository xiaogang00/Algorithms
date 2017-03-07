#include <iostream>
#include "class.h"

using namespace std;

void create_ploy(struct node* ploy1,struct node* ploy2)
{
     ploy1->coef=0;
     ploy1->expn=0;
     ploy1->next=NULL;
     ploy2->coef=0;
     ploy2->expn=0;
     ploy2->next=NULL;
}
void input_ploy(struct node *ploy1,struct node *ploy2)
{
     float first;
     int second;
     while(cin>>first>>second)
     {
     struct node *p=new struct node;
     p->coef=first;
     p->expn=second;
     p->next=ploy1->next;
     ploy1->next=p;
     }
     cout<<"next input"<<endl;
     cin.clear();
     cin.sync();
      while(cin>>first>>second)
     {
     struct node *p=new struct node;
     p->coef=first;
     p->expn=second;
     p->next=ploy2->next;
     ploy2->next=p;
     }    
}
void add_ploy(struct node *ploy1,struct node *ploy2)
{
     struct node *p=ploy1->next;
     while(p!=NULL)
     {
      struct node *q=ploy2->next;
      while(q!=NULL&&p->expn!=q->expn)
      {
       q=q->next;
      }
      if(q==NULL) 
      {
       struct node *r=new struct node;
       r->coef=p->coef;
       r->expn=p->expn;
       r->next=ploy2->next;
       ploy2->next=r;
      }
      else
      {
       q->coef+=p->coef;
      }
      p=p->next;
     }
}
void print_ploy(struct node *ploy)
{
     struct node *p=ploy->next;
     while(p!=NULL)
     {
      cout<<p->coef<<" "<<p->expn<<endl;
      p=p->next;
     }
}
