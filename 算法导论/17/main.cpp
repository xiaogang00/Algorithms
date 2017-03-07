#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
void input(vector<int> &v)
{
     v.push_back(0);
     int data;
     while(cin>>data)
     {
      v.push_back(data);
     }
}
void output(vector<int> &v)
{
     for(vector<int>::iterator c_iter=v.begin();c_iter!=v.end();++c_iter)
     cout<<*c_iter<<" ";
     cout<<endl;
}
void max_heap(vector<int> &v,int heap_len,int i)
{
     int larg=i;
     if(2*i<=heap_len&&v[2*i]>v[larg])
     larg=2*i;
     if(2*i+1<=heap_len&&v[2*i+1]>v[larg])
     larg=2*i+1;
     if(larg!=i)
     {
      int temp=v[i];
      v[i]=v[larg];
      v[larg]=temp;
      max_heap(v,heap_len,larg);
     }
}
void build_heap(vector<int> &v,int heap_len)
{
     for(int i=heap_len/2;i>=1;--i)
     max_heap(v,heap_len,i);
}
void sort_heap(vector<int> &v)
{
     static int heap_len=v.size()-1;
     if(heap_len!=1)
     {
     build_heap(v,heap_len);
     int temp=v[1];
     v[1]=v[heap_len];
     v[heap_len]=temp;
     --heap_len;
     sort_heap(v);
     }
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input(v);
    build_heap(v,v.size()-1);
    sort_heap(v);
    output(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
