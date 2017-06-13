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
void quick_sort(vector<int> &v)
{
     vector<int> res(v.size());
     int k=20;
     vector<int> vc(k+1);
     for(vector<int>::iterator iter=v.begin();iter!=v.end();++iter)
     {
      ++vc[*iter];
     }
     for(int j=1;j<=k;++j)
     {
      vc[j]+=vc[j-1];
     }
     for(int j=v.size()-1;j>=0;--j)
     {
      res[vc[v[j]]-1]=v[j];
      --vc[v[j]];
     }
     print_v(res);
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    quick_sort(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
