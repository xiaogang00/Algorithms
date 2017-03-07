#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
void input(vector<int> &v)
{
     int data;
     while(cin>>data)
     {
      v.push_back(data);
     }
}
int binary_search(vector<int> &v,int low,int high,int elem)
{
    if(low>high) 
    {
     cout<<"no found"<<endl;
     return 0;
    }
    int middle=(high+low)/2;
    if(elem==v[middle]) 
    {
     cout<<middle+1<<endl;
     return 0;
     }
    else if(elem>v[middle]) binary_search(v,middle+1,high,elem);
    else binary_search(v,low,middle-1,elem);
}
int main(int argc, char *argv[])
{
    vector<int> v;
    int elem;
    input(v);
    cin.clear();
    cin.sync();
    cout<<"input the elem to find"<<endl;
    cin>>elem;
    binary_search(v,0,v.size()-1,elem);
    system("PAUSE");
    return EXIT_SUCCESS;
}
