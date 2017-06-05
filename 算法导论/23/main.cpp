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
int hoare_partition(vector<int> &v,int s,int e)
{
    int p=v[s];
    int j=e+1;
    int i=s-1;
    while(1)
    {
     while(v[++i]<p);
     while(v[--j]>p);
     if(i<j)
     {
      int temp=v[i];
      v[i]=v[j];
      v[j]=temp;
     }
     else 
     return j;
    }
}
void h_p_sort(vector<int> &v,int s,int e)
{
     if(s<e)
     {
      int pj=hoare_partition(v,s,e);
      h_p_sort(v,s,pj);
      h_p_sort(v,pj+1,e);
     }
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    h_p_sort(v,0,v.size()-1);
    print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
