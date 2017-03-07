#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> array;
    int data;
    while(cin>>data)    
    {
     array.push_back(data);
    }
    for(int i=1;i<array.size();++i)
    {
     int temp=array[i];
     int j=i-1;
     while(j>=0&&array[i]<array[j])
     {
      --j;
     }
     for(int n=i-1;n>=j+1;--n)
     {
      array[n+1]=array[n];
     }
     array[j+1]=temp;
    }
    for(vector<int>::iterator iter=array.begin();iter!=array.end();++iter)
    {
     cout<<*iter<<" ";
    }
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
