#include <cstdlib>
#include <iostream>
#include "b_tree.h"

using namespace std;

void insert_node(struct tree_node*& b_tree,int data)
{
     struct tree_node *p=new struct tree_node;
     p->key=data;
     p->parent=p->right=p->left=NULL;
     if(b_tree==NULL)
     {
      b_tree=p;
     }
     else
     {
      struct tree_node *q=b_tree;
      struct tree_node *memory;
      while(q!=NULL)
      {
       memory=q;
       if(p->key<q->key)
       {
        q=q->left;
       }
       else if(p->key>q->key)
       {
        q=q->right;
       }
      }
      if(p->key<memory->key)
      {
       memory->left=p;
       p->parent=memory;
      }
      else
      {
       memory->right=p;
       p->parent=memory;
      }
     }
}
struct tree_node min_tree(struct tree_node* b_tree)
{
    struct tree_node *p=b_tree;
    struct tree_node *memory;
    while(p!=NULL)
    {
     memory=p;
     p=p->left;
    }
    return *memory;
}
struct tree_node max_tree(struct tree_node* b_tree)
{
    struct tree_node* p=b_tree;
    while(p->right!=NULL)
    {
     p=p->right;
    }
    return *p;
}
struct tree_node successor(struct tree_node * b_tree,struct tree_node *f_node)
{
       if(f_node->right!=NULL)
       {
        return min_tree(f_node->right);
       }
       else
       {
        struct tree_node *res=f_node->parent;
        while(f_node!=res->left&&res!=NULL)
        {
         f_node=f_node->parent;
         res=f_node->parent;
        }
        return *res;
       }
}

struct tree_node predecessor(struct tree_node* b_tree,struct tree_node *f_node)
{
       if(f_node->left!=NULL)
       return max_tree(f_node->left);
       else
       {
        struct tree_node *res=f_node->parent;
        while(f_node!=res->right&&res!=NULL)
        {
         f_node=f_node->parent;
         res=f_node->parent;
        }
        return *res;
       }
}
void delete_node(struct tree_node* b_tree,int key)
{
     struct tree_node *p=b_tree;
     while(p!=NULL&&p->key!=key)
     {
      if(p->key>key)
      p=p->left;
      else
      p=p->right;
     }
     if(p==NULL)
     {
      cout<<"not exist the key"<<endl;
      return;
     }
     
     
     if(p->left==NULL&&p->right==NULL)            //case 1
     {
      if(p==p->parent->left)
      p->parent->left=NULL;
      else
      p->parent->right=NULL;
     }
     
     
     if(p->left!=NULL&&p->right==NULL)            //case 2
     {
      if(p==p->parent->left)
      {
      p->parent->left=p->left;
      p->left->parent=p->parent;
      }
      else
      {
       p->parent->right=p->left;
       p->left->parent=p->parent;
      }
     }
     if(p->right!=NULL&&p->left==NULL)
     {
      if(p==p->parent->right)
      {     
      p->parent->right=p->right;
      p->right->parent=p->parent;
      }
      else
      {
       p->parent->left=p->right;
       p->right->parent=p->parent;
      }
     }
     
     
     if(p->right!=NULL&&p->left!=NULL)           //case 3
     {
      struct tree_node ss=successor(b_tree,p);
      struct tree_node *s=&ss;
      delete_node(b_tree,s->key);
      if(p==p->parent->left)
      {
       p->parent->left=s;
       s->left=p->left;
       s->right=p->right;
       if(p->left!=NULL)
       p->left->parent=s;
       if(p->right!=NULL)
       p->right->parent=s;
      }
      else
      {
       p->parent->right=s;
       s->left=p->left;
       s->right=p->right;
       if(p->left!=NULL)
       p->left->parent=s;
       if(p->right!=NULL)
       p->right->parent=s;
      }
     }
}
void trace_tree(struct tree_node *b_tree)
{
     struct tree_node *w=b_tree;
     if(w!=NULL)
     {
     trace_tree(w->left);
     cout<<w->key<<" ";
     trace_tree(w->right);
     }
}
 
