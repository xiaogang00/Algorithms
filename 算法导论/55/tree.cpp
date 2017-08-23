#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

#include "tree.h"

using namespace std;

struct tree_node*& string_to_tree(string &str)  //struct tree_node *& :error
{
       stack<struct tree_node *> p_stack;
       for(string::iterator str_iter=str.begin();str_iter!=str.end();++str_iter)
       {
         struct tree_node *p=new struct tree_node;
         p->key=*str_iter;
         p->left=p->right=NULL;
        if(isalnum(*str_iter))
        {
         p_stack.push(p);
        }
        else
        {
         struct tree_node *pr=p_stack.top();
         p_stack.pop();
         struct tree_node *pl=p_stack.top();
         p_stack.pop();
         p->left=pl;
         p->right=pr;
         p_stack.push(p);
        }
       }
       return p_stack.top();
}

void trace_tree(struct tree_node *b_tree)
{
     if(b_tree!=NULL)
     {
      trace_tree(b_tree->left);
      cout<<b_tree->key;
      trace_tree(b_tree->right);
     }
}
