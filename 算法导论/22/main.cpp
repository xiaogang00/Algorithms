#include <cstdlib>
#include <iostream>
#include <vector>

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
int partition(vector<int> &v,int s,int e)
{
    int insert_u=s-1;
    for(int i=s;i<e;++i)
    {
     if(v[i]<v[e])
     {
      int temp=v[++insert_u];
      v[insert_u]=v[i];
      v[i]=temp;
     }
    }
    int temp=v[++insert_u];
    v[insert_u]=v[e];
    v[e]=temp;
    return insert_u;
}
void insert_sort(vector<int> &v,int s,int e)
{
     int i=e;
     if(i>s)
     {
      insert_sort(v,s,i-1);
      int j=i-1;
      while(j>=s&&v[j]>v[i])
      {
       --j;
      }
      int temp=v[i];
      for(int m=i-1;m>=j+1;--m)
      {
       v[m+1]=v[m];
      }
      v[j+1]=temp;
     }
}
void p_insert_sort(vector<int> &v,int s,int e,int k)
{
     if(s<e)
     {
     int flag=0;
     int p=partition(v,s,e);
     if((p-1-s+1)>k)
     {
     p_insert_sort(v,s,p-1,k);
     ++flag;
     }
     if((e-p-1+1)>k)
     {
     p_insert_sort(v,p+1,e,k);
     ++flag;
     }
     if(flag!=2)              //≤Â»Î≈≈–Ú 
     {
      insert_sort(v,s,e);
     }
     }
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    cin.clear();
    cin.sync();
    int k;
    cin>>k;
    p_insert_sort(v,0,v.size()-1,k);
    print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
