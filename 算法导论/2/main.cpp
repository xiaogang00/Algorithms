#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void input(vector<bool> &v)
{
     bool data;
     while(cin>>data)
     {
      v.push_back(data);
     }
}
int main(int argc, char *argv[])
{
    vector<bool> v1,v2;
    input(v1);
    cout<<"next"<<endl;
    cin.clear();
    cin.sync();
    input(v2);
    vector<bool> v(v1.size()>v2.size()?v1.size()+1:v2.size()+1);
    int u=v.size()-1;
    int i,j;
    bool add_to=0;
    bool base;
    for(i=v1.size()-1,j=v2.size()-1;i>=0,j>=0;--i,--j)
    {
     base=(v1[i]+v2[j]+add_to)%2;
     add_to=(v1[i]+v2[j]+add_to)/2;
     v[u]=base;
     --u;
    }
    if(i==-1) 
    {
     while(j>-1)
     {
      base=(v2[j]+add_to)%2;
      add_to=(v2[j]+add_to)/2;
      v[u]=base;
      --u;
      --j;
     }
     v[u]=add_to;
     }
    if(j==-1) 
    {
     while(i>-1)
     {
      base=(v1[i]+add_to)%2;
      add_to=(v1[i]+add_to)/2;
      v[u]=base;
      --u;
      --i;
     }
     v[u]=add_to;     
    }
    for(vector<bool>::iterator iter=v.begin();iter!=v.end();++iter)
    cout<<*iter;
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
