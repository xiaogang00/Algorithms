#include <cstdlib>
#include <iostream>

#define NUM 8

using namespace std;

int site[NUM];

void output()
{
     for(int line=0;line<NUM;line++)
     cout<<site[line]<<" ";
     cout<<endl;     
}
int isvalid(int line)
{
    for(int i=0;i<line;i++)
    {
     if(site[i]==site[line])
     return 0;
     if(abs(site[i]-site[line])==line-i)
     return 0;
    }
    return 1;
}

void queue()
{
     int line=0;
     int row=0;
     int count=0;
     
     while(line>=0)
     {
                   
      for(;row<NUM;row++)                    //寻找line列 可以放Q的行号 
      {
       site[line]=row;
       if(isvalid(line))
       break;
      }
      
      if(row==NUM)                         //在line列已经没有合适的位置了 
      {
       line--;
       row=site[line]+1;
      }
      else
      {
       if(line==NUM-1)                   //有解了
        {
         output();
         cout<<endl;
         count++;
         row++;
        }
        else
        {
         line++;
         row=0;
        } 
      }
     }
     cout<<count<<endl;
}
int main(int argc, char *argv[])
{
    queue();
    system("PAUSE");
    return EXIT_SUCCESS;
}
