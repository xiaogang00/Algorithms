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
    for(int i=s;i<e;++i)
    {
     if(v[i]<p)
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

void p_sort(vector<int> &v,int s,int e)
{
     if(s<e)
     {
      int i=partition(v,s,e);
      p_sort(v,s,i-1);
      p_sort(v,i+1,e);
     }
}
int b_search(vector<int> &v,int low,int high,int elem)
{
    if(low>high)
    {
     if(high==-1)
     return -1;
     else
     return (low+high)/2;
    }
    else
    {
      int middle=(low+high)/2;
      if((v[middle]<=elem)&&(elem<v[middle+1]))
      {
       return middle;
      }
      if((v[middle]>elem)&&(v[middle+1]>elem))
      {
       return b_search(v,low,middle-1,elem);
      }
      if((v[middle]<=elem)&&(v[middle+1]<=elem))
      {
       return b_search(v,middle+1,high,elem);
      }
    }
}
void sub_x(vector<int> &v,int res)        //qiu sub result>=res
{
     for(int i=0;i<v.size();++i)
     {
      int elem=v[i]-res;
      int p=b_search(v,0,v.size(),elem);
      if(p!=-1)
      {
       for(int j=0;j<=p;++j)
       {
       cout<<v[i]<<" "<<v[p]<<endl;
       }
      }
     }
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    p_sort(v,0,v.size()-1);
    cin.clear();
    cin.sync();
    int res;
    cin>>res;
    sub_x(v,res);
    //print_v(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
