#include <cstdlib>
#include <iostream>
#include <string>

#include "tree.h"

using namespace std;
void init(struct tree_node*& b_tree)
{
     b_tree=new struct tree_node;
     b_tree->flag=0;
     b_tree->left=b_tree->right=NULL;
}
void insert_node(struct tree_node* b_tree,string str)
{
     int len=str.size();
     struct tree_node *qt=b_tree;
     for(string::iterator c_iter=str.begin();c_iter!=str.end();++c_iter)
     {
      if(*c_iter=='1')             //找位置 
      {
       if(qt->right!=NULL)
       qt=qt->right;
       else
       {
        struct tree_node *p=new struct tree_node;
        p->left=p->right=NULL;
        p->flag=0;
        qt->right=p;
        qt=p;
       }
       
       if(len==1)                    //修改节点数据 
       {
        qt->key=str;
        qt->flag=1;
       }    
      }
      else
      {
       if(qt->left!=NULL)
       qt=qt->left;
       else
       {
        struct tree_node *p=new struct tree_node;
        p->left=p->right=NULL;
        p->flag=0;
        qt->left=p;
        qt=p;
       }
       
       if(len==1)
       {
        qt->key=str;
        qt->flag=1;
       }
       
      }
      --len;
     }
}

void trace_tree(struct tree_node *b_tree)
{
     if(b_tree!=NULL)
     {
      if(b_tree->flag==1)
      cout<<b_tree->key<<" "<<endl;
      trace_tree(b_tree->left);
      trace_tree(b_tree->right);
     }
}
