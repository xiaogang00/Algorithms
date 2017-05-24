#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>

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
     for(vector<int>::const_iterator iter=v.begin();iter!=v.end();++iter)
     cout<<*iter<<" ";
     cout<<endl;
}
int partition(vector<int> &v,int s,int e)
{
    srand((unsigned int)time(NULL));
    int p=rand()%(e-s+1)+s;
    int temp=v[p];
    v[p]=v[e];
    v[e]=temp;
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
    temp=v[e];
    v[e]=v[++insert_u];
    v[insert_u]=temp;
    return insert_u;
}
void p_sort(vector<int> &v,int s,int e)
{
     if(s<e)
     {
      int p=partition(v,s,e);
      p_sort(v,s,p-1);
      p_sort(v,p+1,e);
     }
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    p_sort(v,0,v.size()-1);
    print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
