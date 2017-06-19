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

void search_max_min(vector<int> &v)
{
     int max,min;
     int for_start;
     if(v.size()/2)
     {
      max=v[0];
      min=v[0];
      for_start=1;
     }
     else
     {
      if(v[0]>v[1])
      {
       max=v[0];
       min=v[1];
      }
      else 
      {
       max=v[1];
       min=v[0];
      }
      for_start=2;
     }
     
     for(int i=for_start;i<v.size()-1;++i)
     {
      if(v[i]>v[i+1])
      {
       if(v[i]>max)
       max=v[i];
       if(v[i+1]<min)
       min=v[i+1];
      }
      else
      {
       if(v[i+1]>max)
       max=v[i+1];
       if(v[i]<min)
       min=v[i];
      }
     }
     cout<<max<<" "<<min<<endl;
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    search_max_min(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
