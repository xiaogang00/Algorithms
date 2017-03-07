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
void output(vector<int> v)
{
     for(vector<int>::iterator iter=v.begin();iter!=v.end();++iter)
     {
      cout<<*iter<<" ";
     }
}
int b_search(vector<int> &v,int low,int high,int elem)
{
    //if(low==high&&v[high+1]==elem) return high;
    if(low>high) return -1;
    else
    {
     int middle=(low+high)/2;
     if(v[middle]<=elem&&v[middle+1]>=elem) 
     return middle;
     else if(v[middle]<elem&&v[middle+1]<elem)
      return b_search(v,middle+1,high,elem);             //´íÎó £º²»¼Óreturn  
     else
     return b_search(v,low,middle-1,elem);
    }
}
void b_insert_sort(vector<int> &v,int i)
{
     if(i>0)
     {
     b_insert_sort(v,i-1);
     int u=b_search(v,0,i-1,v[i]);
     int temp=v[i];
     for(int m=i-1;m>=u+1;--m)
     v[m+1]=v[m];
     v[u+1]=temp;                  //     v[u+1]=v[i]
     }
}

int main(int argc, char *argv[])
{
    vector<int> v;
    input(v);
    b_insert_sort(v,v.size()-1);
    output(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
