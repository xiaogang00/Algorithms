#include <cstdlib>
#include <iostream>

#include "tree.h"

using namespace std;

void insert_node(struct tree_node*& b_tree,int elem)
{
     if(b_tree==NULL)
     {
      b_tree=new struct tree_node;
      b_tree->key=elem;
      b_tree->left=b_tree->right=NULL;
     }
     else
     {
      struct tree_node *p=b_tree;
      struct tree_node *p_flag;
      while(p!=NULL)
      {
       p_flag=p;
       if(p->key>elem)
       p=p->left;
       else
       p=p->right;
      }
      struct tree_node *q=new struct tree_node;
      q->key=elem;
      q->left=q->right=NULL;
      if(p_flag->key>elem)
      p_flag->left=q;
      else
      p_flag->right=q;
     }
}

struct tree_node* copy_insert(struct tree_node *b_tree,int elem)
{
       struct tree_node *p=b_tree;
       struct tree_node *b_tree2=new struct tree_node(*b_tree);
       struct tree_node *q=b_tree2;
       while(p!=NULL)
       {
                     
        if(p->key<elem)
        {
         p=p->right;
         struct tree_node *w=new struct tree_node;
         if(p!=NULL)
         {
          w->key=p->key;
          w->left=p->left;
          w->right=p->right;
          q->right=w;
          q=w;
         }
         else
         {
          w->key=elem;
          w->left=w->right=NULL;
          q->right=w;
         }
        }
        
        
        else
        {
         p=p->left;
         struct tree_node *w=new struct tree_node;
         if(p!=NULL)
         {
          w->key=p->key;
          w->left=p->left;
          w->right=p->right;
          q->left=w;
          q=w;
         }
         else
         {
          w->key=elem;
          w->left=w->right=NULL;
          q->left=w;
         }
        }
        
       }
       
       return b_tree2;
}
void trace_tree(struct tree_node *b_tree)
{
     if(b_tree!=NULL)
     {
      trace_tree(b_tree->left);
      cout<<b_tree->key<<" ";
      trace_tree(b_tree->right);
     }
}
