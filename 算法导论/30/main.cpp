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
    int p=v[e];
    int insert_u=s-1;
    int i=s;
    while(i<e)
    {
     if(v[i]<p)
     {
      int temp=v[i];
      v[i]=v[++insert_u];
      v[insert_u]=temp;
     }
     ++i;
    }
    int temp=v[++insert_u];
    v[insert_u]=v[e];
    v[e]=temp;
    return insert_u;
}
void select(vector<int> &v,int s,int e,int i)
{
     int j=partition(v,s,e);
     if(j==i-1)
     cout<<v[j]<<endl;
     else if(j<i-1)
     select(v,j+1,e,i);
     else
     select(v,s,j-1,i);
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    cin.clear();
    cin.sync();
    cout<<"input you want to select:";
    int i;
    cin>>i;
    select(v,0,v.size()-1,i);
    system("PAUSE");
    return EXIT_SUCCESS;
}
