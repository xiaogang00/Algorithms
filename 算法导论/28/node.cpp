#include <iostream>
#include <vector>

#include "node.h"

using namespace std;


void input_v(vector<int> &v)
{
     int data;
     while(cin>>data)
     {
      v.push_back(data);
     }
}
void print_v(const vector<int> &v)
{
     for(vector<int>::const_iterator c_iter=v.begin();c_iter!=v.end();++c_iter)
     cout<<*c_iter<<" ";
     cout<<endl;
}
void sort(vector<int> &v)
{
     struct node *p[10];
     for(int i=0;i<10;++i)
     {
      p[i]=new struct node;
      p[i]->data=i;
      p[i]->next=NULL;
     }
     for(int i=0;i<v.size();++i)
     {
      struct node *q=new struct node;
      q->data=v[i];
      q->next=p[v[i]]->next;
      p[v[i]]->next=q;
     }
     v.clear();
     for(int i=0;i<10;++i)
     {
      struct node *q=p[i];
      while(q->next!=NULL)
      {
       v.push_back(q->data);
       q=q->next;
      }
     }
}

