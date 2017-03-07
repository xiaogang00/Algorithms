#include <cstdlib>
#include <iostream>
#include  <vector>

using namespace std;

void input(vector<int> &v)
{
     int data;
     while(cin>>data)
     {
     v.push_back(data);
     }
}
int insert_sort(vector<int> &v,int i)
{
     if(i==0) 
     {
      cout<<"ok"<<endl;
      return 0;
     }
     insert_sort(v,i-1);
     int temp=v[i];
     int j=i-1;
     while(j>=0&&v[j]>v[i])
     {
      --j;
     }
     for(int m=i-1;m>=j+1;--m)
     {
      v[m+1]=v[m];
     }
     v[j+1]=temp;
}
void output(vector<int> &v)
{
     for(vector<int>::iterator iter=v.begin();iter!=v.end();++iter)
     cout<<*iter<<" ";
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input(v);
    insert_sort(v,v.size()-1);
    output(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
