#include <cstdlib>
#include <iostream>
#include <vector>
#define INFINITY -10000

using namespace std;
void sort_v(vector<int> &v)
{
     for(int i=1;i<v.size();++i)
     {
      int temp=v[i];
      int j=i-1;
      while(j>=0&&v[j]<v[i])
      {
       --j;
      }
      for(int n=i-1;n>j;--n)
      {
       v[n+1]=v[n];
      }
      v[j+1]=temp;
     }
}
vector<int> merge1(vector<int> &v1,vector<int> &v2)
{
     vector<int> res;
     vector<int>::iterator it1,it2;
     it1=v1.begin();
     it2=v2.begin();
     while(it1!=v1.end()&&it2!=v2.end())
     {
      if(*it1>*it2)
      {
      res.push_back(*it1);
      ++it1;
      }
      else
      {
       res.push_back(*it2);
       ++it2;
       }
     }
     if(it1==v1.end())
     {
      while(it2!=v2.end())
      {
       res.push_back(*it2);
       ++it2;
      }
     }
     else
     {
      while(it1!=v1.end())
      {
       res.push_back(*it1);
       ++it1;
      }
     }
     return res;
}
vector<int> merge2(vector<int> &v1,vector<int> &v2)
{
      v1.push_back(INFINITY);
      v2.push_back(INFINITY);
      vector<int> res;
      int m=0;
      int n=0;
      for(int i=0;i!=v1.size()+v2.size()-2;++i)
      {
       if(v1[m]>v2[n])
       {
        res.push_back(v1[m]);
        ++m;
       } 
       else
       {
        res.push_back(v2[n]);
        ++n;
       }
      }
      return res;
}
void print_v(vector<int> &v)
{
     for(vector<int>::iterator iter=v.begin();iter!=v.end();++iter)
     {
      cout<<*iter<<" ";
     }
     cout<<endl;
}
int main(int argc, char *argv[])
{
    vector<int> v1,v2;
    int data;
    while(cin>>data)
    v1.push_back(data);
    cin.clear();
    cin.sync();
    while(cin>>data)
    v2.push_back(data);
    sort_v(v1);
    sort_v(v2);
    vector<int> v(merge1(v1,v2));
    vector<int> vv(merge2(v1,v2));
    print_v(v);
    print_v(vv);
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
