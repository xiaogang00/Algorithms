#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
void init_v(vector<int> &v)
{
     v.push_back(0);
}
void add_elem(vector<int> &v,int data)        //…œ∏° 
{
     v.push_back(data);
     int child=v.size()-1;
     int parent=child/2;
     while(parent!=0&&v[parent]<v[child])
     {
      int temp=v[child];
      v[child]=v[parent];
      v[parent]=temp;
      child=parent;
      parent=child/2;
     }
}
int max_v(vector<int> &v)
{
    return v[1];
}
int max_extract_v(vector<int> &v)
{
    int res=v[1];
    v[1]=v[v.size()-1];
    v.pop_back();
    int heap_len=v.size()-1;
    int i=1;
    while(1)
    {
     int larg=i;
     if(2*i<heap_len&&v[2*i]>v[larg])
     larg=2*i;
     if(2*i+1<heap_len&&v[2*i+1]>v[larg])
     larg=2*i+1;
     if(larg!=i)
     {
      int temp=v[i];
      v[i]=v[larg];
      v[larg]=temp;
      i=larg;
     }
     else
     break;
    }
}
void print_v(const vector<int> &v)
{
     for(vector<int>::const_iterator iter=v.begin()+1;iter!=v.end();++iter)
     cout<<*iter<<" ";
     cout<<endl;
}
int main(int argc, char *argv[])
{
    vector<int> v;
    init_v(v);
    int data;
    while(cin>>data)
    {
     add_elem(v,data);
    }
    print_v(v);
    max_extract_v(v);
    
    print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
