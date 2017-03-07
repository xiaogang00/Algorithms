#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &v)
{
     int data;
     v.push_back(0);
     while(cin>>data)
     v.push_back(data);
}
void output(const vector<int> &v)
{
     for(vector<int>::const_iterator iter=v.begin();iter!=v.end();++iter)
     cout<<*iter<<" ";
     cout<<endl;
}
void max_heap(vector<int> &v,int i)
{
     int heap_len=v.size()-1;
     if(i>heap_len)
     {
      cout<<"overflow"<<endl;
      exit(0);
     }
     int larg=i;
     if(2*i<=heap_len&&v[2*i]>v[larg])
     larg=2*i;
     if(2*i+1<=heap_len&&v[2*i+1]>v[larg])     //else if和if是有区别的，错误 
     larg=2*i+1;       
     if(larg!=i)
     {
      int temp=v[i];
      v[i]=v[larg];
      v[larg]=temp;
      max_heap(v,larg);
     }
}
void build_heap(vector<int> &v)
{
     int heap_len=v.size()-1;
     for(int i=heap_len/2;i>=1;--i)
     max_heap(v,i);
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input(v);
    build_heap(v);
    output(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
