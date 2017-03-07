#include <cstdlib>
#include <iostream>
#include <vector>
#define INFINITE 10000

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
     for(int i=p;i<=q;++i)
     v1.push_back(v[i]);
     v1.push_back(INFINITE);
     for(int i=q+1;i<=r;++i)
     v2.push_back(v[i]);
     v2.push_back(INFINITE);
     int m=0;
     int n=0;
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
void search(vector<int> &v,int elem)
{
     int start=0;
     int end=v.size()-1;
     while(start<end)
     {
      if(v[start]+v[end]==elem)
      {
       cout<<v[start]<<" "<<v[end]<<endl;
       ++start;
       --end;
      }
      else 
      {
       --end;
      }
     }
}

int main(int argc, char *argv[])
{
    vector<int> v;
    int data;
    input(v);
    cout<<"input the sum number"<<endl;
    cin.clear();
    cin.sync();
    cin>>data;
    merge_sort(v,0,v.size()-1);
    search(v,data);
    system("PAUSE");
    return EXIT_SUCCESS;
}
