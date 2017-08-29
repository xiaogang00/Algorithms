#include <cstdlib>
#include <iostream>
#include <string>
#define N 8

using namespace std;

string str1("abedfffg");
string str2("abcdvfff");
int site[N][N];
int select[N]={0};

void init()
{
     for (int i = 0;i < N;i++)
     {
         for (int j = 0;j < N;j++)
         {
             site[i][j] = -1;
         }
     }
}
void print()
{
     for (int i = 0;i < N;i++)
     {
         if (select[i] == 1)
         cout<<str1[i];
     }
     cout<<endl;
}
int lcs(int i,int j)
{
     if (i<0||j<0)
     {
        return 0;
     }
     if (site[i][j]==-1)
     {
        int k=j;
        while (k >= 0 && str2[k] != str1[i])
        {
           k--;
        }
        if (k == -1)    /*optimal is select1*/
        {
           return lcs(i-1,j);
        }
        else
        {
            int res1=lcs(i-1,j);
            int res2=lcs(i-1,k-1)+1;
            site[i][j]=res2>res1?res2:res1; /*optimal must compare*/
            if(res2>res1)
            select[i]=1;
        }
     }
     return site[i][j];
}
int lcs2(int i,int j)
{
    if(i<0||j<0)
    {
     return 0;
    }
    int k=j;
    while (k>=0&&str2[k]!=str1[i])
    {
          k--;
    }
    if (k==-1)
    {
       return lcs2(i-1,j);
    }
    else
    {
        int res1=lcs2(i-1,k-1)+1;
        int res2=lcs2(i-1,j);
        return res1>res2?res1:res2;
    }
}
int main(int argc, char *argv[])
{
    init();
    int maxLen=lcs(N-1,N-1);
    cout<<maxLen<<endl;
    print();
    system("PAUSE");
    return EXIT_SUCCESS;
}
