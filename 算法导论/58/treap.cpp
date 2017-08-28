#include <cstdlib>
#include <iostream>

#include "treap.h"

using namespace std;

void rotate_left(struct treap_node*& k)
{
     struct treap_node *p=k->left;
     k->left=p->right;
     p->right=k;
     k=p;
}
void rotate_right(struct treap_node*& k)
{
     struct treap_node *p=k->right;
     k->right=p->left;
     p->left=k;
     k=p;
}

void insert_node(struct treap_node *&treap,int key,int pr)
{
     if(treap==NULL)
     {
      struct treap_node *p=new struct treap_node;
      p->left=p->right=NULL;   
      p->key=key;
//      int priority=rand();       //rand number
      p->priority=pr;
      treap=p;
     }
     else
     {
      if(treap->key>key)
      {
       insert_node(treap->left,key,pr);
       if(treap->left->priority<treap->priority)
       rotate_left(treap);
      }
      else
      {
       insert_node(treap->right,key,pr);
       if(treap->right->priority<treap->priority)
       rotate_right(treap);
      }
     }
}

void trace_tree(struct treap_node *treap)
{
     if(treap!=NULL)
     {
      trace_tree(treap->left);
      cout<<treap->key<<" ";
      trace_tree(treap->right);
     }
}

