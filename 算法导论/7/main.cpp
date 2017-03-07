#include <cstdlib>
#include <iostream>
#include <vector>
#define INFINITE 1000

using namespace std;

void input(vector<int> &v)
{
     int data;
     while(cin>>data)
     {
      v.push_back(data);
     }
}

void merge(vector<int> &v,int p,int q,int r)
{
     vector<int> v1,v2;
     int m=0;
     int n=0;
     for(int i=p;i<=q;++i)
     v1.push_back(v[i]);
     v1.push_back(INFINITE);
     for(int i=q+1;i<=r;++i)
     v2.push_back(v[i]);
     v2.push_back(INFINITE);
     for(int i=p;i<=r;++i)
     {
      if(v1[m]<v2[n])
      {
       v[i]=v1[m];
       ++m;
      }
      else 
      {
       v[i]=v2[n];
       ++n;
      }
     }
}
void merge_sort(vector<int> &v,int p,int r)
{
     if(p<r)
     {
      int q=(p+r)/2;
      merge_sort(v,p,q);
      merge_sort(v,q+1,r);
      merge(v,p,q,r);
     }
}
void output(vector<int> &v)
{
     for(vector<int>::iterator iter=v.begin();iter!=v.end();++iter)
     cout<<*iter<<" ";
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input(v);   
    merge_sort(v,0,v.size()-1);
    output(v);
    system("PAUSE");
    return EXIT_SUCCESS;
    

}
