#include <cstdlib>
#include <iostream>

using namespace std;
void init(int *array)
{
     for(int i=0;i<4;++i)
     {array[i]=-1;}
}
void line(int *array)
{
     int data;
     while(cin>>data)
     {
      int hk=data%4;
      int size=4;
      while(array[hk]!=-1&&size--!=0)
      {
       hk=(hk+1)%4;
      }
      if(size==-1)
      {
      cout<<"no space"<<endl;
      return;
      }
      else
      array[hk]=data;
     }
}
void find_line(int *array,int elem)
{
     int hk=elem/4;
     int size=4;
     while(array[hk]!=-1&&array[hk]!=elem&&size--!=0)
     {
      hk=(hk+1)%4;
     }
     if(array[hk]==-1)
     {
     cout<<"not found"<<endl;
     return;
     }
     else
     cout<<hk<<endl;
}
void print(int *array)
{
     for(int i=0;i<4;++i)
     cout<<array[i]<<" ";
     cout<<endl;
}
int main(int argc, char *argv[])
{
    int array[4];
    init(array);
    line(array);
    cin.clear();
    cin.sync();
    int data;
    cin>>data;
    find_line(array,data);
    print(array);
    system("PAUSE");
    return EXIT_SUCCESS;
}
