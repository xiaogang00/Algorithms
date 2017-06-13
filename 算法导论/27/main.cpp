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

vector<int>& count_v(const vector<int> &v)
{
             int k=20;                //0~K之间的数 
             vector<int> vc(k+1);
             for(int i=0;i<v.size();++i)
             {
              ++vc[v[i]];
             }
             static vector<int> vcc(vc);
             for(int i=1;i<=k;++i)
             {
              vcc[i]+=vcc[i-1];
             }
             return vcc;
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input_v(v);
    vector<int> count(count_v(v));
    cin.clear();
    cin.sync();
    cout<<"input your count range:"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<count[b]-count[a]<<endl;          //求(a,b]的元素个数 
    system("PAUSE");
    return EXIT_SUCCESS;
}
