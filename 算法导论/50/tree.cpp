#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

void insert_node(struct tree_node*& b_tree,int elem)
{
     if(b_tree==NULL)
     {
      struct tree_node *p=new struct tree_node;
      p->key=elem;
      p->left=p->right=NULL;
      b_tree=p; 
     }
     else 
     {
      if(b_tree->key>elem)
      {
       if(b_tree->left!=NULL)
       {
        insert_node(b_tree->left,elem);
       }
       else
       {
        struct tree_node *p=new struct tree_node;
        p->key=elem;
        p->left=p->right=NULL;
        b_tree->left=p;
       }
      }
      else
      {
          if(b_tree->right!=NULL)
          {
           insert_node(b_tree->right,elem);
          }
          else
          {
           struct tree_node *p=new struct tree_node;
           p->key=elem;
           p->right=p->left=NULL;
           b_tree->right=p;
          }
      }
     }
     
}

void trace_tree(struct tree_node* b_tree)
{
     if(b_tree!=NULL)
     {
      trace_tree(b_tree->left);
      cout<<b_tree->key<<" ";
      trace_tree(b_tree->right);
     }
}
void p_trace_tree(struct tree_node* b_tree)
{
     if(b_tree!=NULL)
     {
     cout<<b_tree->key<<" ";
     p_trace_tree(b_tree->left);
     p_trace_tree(b_tree->right);
     }
}

void l_trace_tree(struct tree_node* b_tree)
{
     if(b_tree!=NULL)
     {
     l_trace_tree(b_tree->left);
     l_trace_tree(b_tree->right);
     cout<<b_tree->key<<" ";
     }
}
