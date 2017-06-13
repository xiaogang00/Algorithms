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

void stooge_sort(vector<int> &v,int s,int e)
{
     if(v[s]>v[e])
     {
      int temp=v[s];
      v[s]=v[e];
      v[e]=temp;
     }
     if(s+1>=e)
     return;
     int k=(e-s+1)/3;
     stooge_sort(v,s,e-k);
     stooge_sort(v,s+k,e);
     stooge_sort(v,s,e-k);
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    stooge_sort(v,0,v.size()-1);
    print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
