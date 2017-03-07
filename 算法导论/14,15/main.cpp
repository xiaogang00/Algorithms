#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &v)
{
     int data;
     v.push_back(0);
     while(cin>>data)
     v.push_back(data);
}
void max_heap(vector<int> &v,int i)
{
     if(i>v.size()) 
     {
      cout<<"overflow"<<endl;
      exit(0);
     }
     int largest=i;
     int heap_len=v.size()-1;
     if((2*i<=heap_len)&&(v[2*i]>v[largest])) 
     largest=2*i;
     else if(2*i+1<=heap_len&&v[2*i+1]>v[largest])
     largest=2*i+1;
     if(largest!=i)
     {
      int temp=v[i];
      v[i]=v[largest];
      v[largest]=temp;
      max_heap(v,largest);
     }
     else                   //不要一下这段也可以，函数执行到 } 就返回 
     {
      cout<<"ok"<<endl;
      return;
     }
}
void max_heap_effective(vector<int> &v,int i)
{
     int heap_len=v.size()-1;
     while(i<heap_len)
     {
      int largest=i;
      if((2*i<=heap_len)&&(v[2*i]>v[largest])) 
      largest=2*i;
      else if(2*i+1<=heap_len&&v[2*i+1]>v[largest])
      largest=2*i+1;
      if(largest!=i)
      {
       int temp=v[i];
       v[i]=v[largest];
       v[largest]=temp;
       i=largest;
      }
      else
      break;
     }
}
void output(const vector<int> &v)
{
     for(vector<int>::const_iterator iter=v.begin();iter!=v.end();++iter)
     cout<<*iter<<" ";
     cout<<endl;
}
int main(int argc, char *argv[])
{
    vector<int> v;
    input(v);
    cin.clear();
    cin.sync();
    cout<<"the sort root: ";
    int i;
    cin>>i;
    max_heap_effective(v,i);
    output(v);
    system("PAUSE");
    return EXIT_SUCCESS;
}
