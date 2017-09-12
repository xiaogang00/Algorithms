#include <cstdlib>
#include <iostream>
#define N 4
using namespace std;

int vec[N]={1,2,3,4};

void swap(int &a,int &b)
{
     int tmp=a;
     a=b;
     b=tmp;
}
void print()
{
     for(int i=0;i<N;i++)
     cout<<vec[i]<<" ";
     cout<<endl;
}
void go(int i)
{
     if(i>=N)
     {
      print();
      return;
     }
     for(int j=i;j<N;j++)
     {
      swap(vec[i],vec[j]);
      go(i+1);
      swap(vec[i],vec[j]);            //»Ö¸´ 
     }
}
int main(int argc, char *argv[])
{
    go(0);
    system("PAUSE");
    return EXIT_SUCCESS;
}
