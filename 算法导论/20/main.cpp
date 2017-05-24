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
     for(vector<int>::const_iterator iter=v.begin();iter!=v.end();++iter)
     cout<<*iter<<" ";
     cout<<endl;
}
int partition(vector<int> &v,int start,int end)
{
    int insert_u=start-1;
    for(int i=start;i<end;++i)
    {
     if(v[i]<v[end]) 
     {
      ++insert_u;
      int temp=v[insert_u];
      v[insert_u]=v[i];
      v[i]=temp;
     }
    }
    int temp=v[++insert_u];
    v[insert_u]=v[end];
    v[end]=temp;
    return insert_u;
}
void p_sort(vector<int> &v,int s,int e)
{
     if(s<e)
     {
      int u=partition(v,s,e);
      p_sort(v,s,u-1);
      p_sort(v,u+1,e);
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
