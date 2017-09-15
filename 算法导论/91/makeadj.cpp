#include "head.h"
#include "node.h"

using namespace std;

void input(char *filename,struct node *(v[N]))
{
     for(int i=0;i<N;i++)
     {
      v[i]=new struct node;
      v[i]->seq=i;
      v[i]->weight=0;
      v[i]->next=NULL;
     }
     fstream infile(filename,fstream::in);
     string aline;
     while(getline(infile,aline))
     {
      stringstream str(aline);
      struct node *p=new struct node;
      int tag;
      str>>tag>>p->seq>>p->weight;
      p->next=v[tag]->next;
      v[tag]->next=p;
     }
     infile.close();
}
