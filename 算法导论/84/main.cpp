#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#define MAX 1000
using namespace std;

int main(int argc, char *argv[])
{
    fstream infile("e:\\in.txt",fstream::in);
    int num;
    infile>>num;
    int data;
    vector<int> array;
    int i=0;
    while(infile>>data)                  //读入数据 
    {
     array.push_back(data);
    }
    int max_len[num];                   //初始化当前位置的最大长度 
    for(int i=0;i<num;i++)
    {
     max_len[i]=1;
    }
    int res_max=1; 
    for(int i=1;i<num;i++)              //计算每一个元素的最大长度 
    {
     int max=1;
     for(int j=0;j<i;j++)
     {
      if(array[i]<=array[j]&&max<max_len[j]+1)
      {
       max=max_len[j]+1;
      }
     }
     max_len[i]=max;
     if(max>res_max)
     {
      res_max=max;
     }
    }
    cout<<res_max<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
