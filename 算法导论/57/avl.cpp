#include <cstdlib>
#include <iostream>

#include "avl.h"

using namespace std;
int height(struct avl_node *k)
{
    return k==NULL?-1:k->height;
}
int max_lr(struct avl_node *m,struct avl_node *n)
{
    return height(m)>height(n)?height(m):height(n);
}
void rotate_left(struct avl_node*& k2)
{
     struct avl_node *k1=k2->left;
     k2->left=k1->right;
     k1->right=k2;
     k2->height=max_lr(k2->left,k2->right)+1;
     k1->height=max_lr(k1->left,k1->right)+1;
     k2=k1;
}

void rotate_right(struct avl_node*& k2)
{
     struct avl_node *k1=k2->right;
     k2->right=k1->left;
     k1->left=k2;
     k2->height=max_lr(k2->left,k2->right)+1;
     k1->height=max_lr(k1->left,k1->right)+1;
     k2=k1;
}

void double_rotate_left(struct avl_node*& k3)
{
     rotate_right(k3->left);
     rotate_left(k3);
}

void double_rotate_right(struct avl_node*& k3)
{
     rotate_left(k3->right);
     rotate_right(k3);
}

void insert_node(struct avl_node*& avl_tree,int elem)
{
     if(avl_tree==NULL)
     {
      struct avl_node *p=new struct avl_node;
      p->left=p->right=NULL;
      p->key=elem;
      p->height=0;
      avl_tree=p;
     }
     else if(elem<avl_tree->key)
     {
         insert_node(avl_tree->left,elem);
         if(height(avl_tree->left)-height(avl_tree->right)>=2)
         {
          if(elem<avl_tree->left->key)
          rotate_left(avl_tree);
          else
          double_rotate_left(avl_tree);
         }
     }
     else if(elem>avl_tree->key)
     {
          insert_node(avl_tree->right,elem);
          if(height(avl_tree->right)-height(avl_tree->left)>=2)
          {
           if(elem>avl_tree->right->key)
           rotate_right(avl_tree);
           else
           double_rotate_right(avl_tree);
          }
     }
     else
     ;
     avl_tree->height=max_lr(avl_tree->left,avl_tree->right)+1;
}

void trace_tree(const struct avl_node* avl_tree)
{
     if(avl_tree!=NULL)
     {
      trace_tree(avl_tree->left);
      cout<<avl_tree->key<<" "<<avl_tree->height<<endl;
      trace_tree(avl_tree->right);
     }
}
