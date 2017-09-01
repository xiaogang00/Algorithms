#include <cstdlib>
#include <iostream>

#define NUM 8

using namespace std;

int site[NUM];        //每一行存放的位置 

int isvalid(int row)
{
    for(int i=0;i<row;i++)
    {
     if(site[row]==site[i])
     return 0;
     if(abs(site[row]-site[i])==(row-i))
     return 0;
    }
    return 1;
}
void output()
{
     for(int row=0;row<NUM;row++)
     {
      for(int line=0;line<NUM;line++)
      {
       if(line==site[row])
       cout<<"q"<<" ";
       else
       cout<<"*"<<" ";
      }
      cout<<endl;
     }
}
int main(int argc, char *argv[])
{
    int row=0;
    int line=0;
    int count=0;
    while(row>=0)    //row
    {
     for(;line<NUM;line++)    //line
     {
      site[row]=line;
      if(isvalid(row))
      break;
     }
     if(line==NUM)         //NO Suitable 
     {
      row--;              
      line=site[row]+1;
     }
     else
     {
      if(row==NUM-1)
      {
       count++;
       output();
       cout<<endl<<endl;
       line=site[row]+1;
      }
      else
      {
      row++;
      line=0;
      }
     }
    }
    cout<<count<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
