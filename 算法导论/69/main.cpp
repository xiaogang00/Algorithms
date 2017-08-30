#include <cstdlib>
#include <iostream>

#define NUM 8

using namespace std;

int site[NUM];

int isvalid(int line)
{
    for(int i=0;i<line;i++)
    {
     if(site[i]==site[line])
     return 0;
     if(abs(site[i]-site[line])==(line-i))
     return 0;
    }
    return 1;
}
void output()
{
     for(int i=0;i<NUM;i++)
     {
      cout<<site[i]<<" ";
     }
}
void queue(int line)
{
     int i;
     if(line==NUM)
     {
      output();
      cout<<endl;
      return ;
     }
     else
     {
      for(int i=0;i<NUM;i++)
      {
       site[line]=i;
       if(isvalid(line))
       queue(line+1);
      }
     }
} 
int main(int argc, char *argv[])
{
    queue(0);
    system("PAUSE");
    return EXIT_SUCCESS;
}
