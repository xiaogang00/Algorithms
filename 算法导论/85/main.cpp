#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#define MAX_CITY 100
#define MAX_DAY 100
#define MAX_COST 1000
using namespace std;
vector<int> ctoc[MAX_CITY][MAX_CITY];
int cost[MAX_DAY][MAX_CITY]={0};
int city_num;
int day_num;
void readfile()
{
     fstream infile("e:\\in.txt",fstream::in);
     string num_str;
     getline(infile,num_str);
     stringstream num_strm(num_str);
     num_strm>>city_num>>day_num;
     string str;
     for(int i=0;i<city_num;i++)
     {
      for(int j=0;j<i;j++)
      {
       getline(infile,str);
       stringstream strm(str);
       int data;
       while(strm>>data)
       {
       ctoc[i][j].push_back(data);
       }
      }
      for(int j=i+1;j<city_num;j++)
      {
       getline(infile,str);
       stringstream strm(str);
       int data;
       while(strm>>data)
       {
        ctoc[i][j].push_back(data);
       }        
      }
     }
}
void cost_cal_one(int day,int city)
{
     int min_cost=MAX_COST;
     for(int i=0;i<city_num;i++) 
     {
      if(i!=city)
      {
       int realday=(day-1)%ctoc[i][city][0]+1;
       if(ctoc[i][city][realday]!=0)
       {
        if(min_cost>(cost[day-1][i]+ctoc[i][city][realday]))
        min_cost=cost[day-1][i]+ctoc[i][city][realday];
       }
      }
     }
     cost[day][city]=min_cost;
}
void cost_cal()
{
     for(int i=1;i<city_num;i++)              //初始化第一天的cost
     {
      if(ctoc[0][i][1]!=0)
      cost[1][i]=ctoc[0][i][1];
     }
     for(int day=2;day<=day_num;day++)
     {
      for(int city=0;city<city_num;city++)
      {
       cost_cal_one(day,city);
      }
     }
}
void print()
{
     int min_cost=MAX_COST;
     for(int day=1;day<=day_num;day++)
     {
      cout<<day<<"  ";
      for(int i=0;i<city_num;i++)
      {
       cout<<cost[day][i]<<" ";
      }
      cout<<endl;
     }
}
int main(int argc, char *argv[])
{
    readfile();
    cost_cal();
    print();
    system("PAUSE");
    return EXIT_SUCCESS;
}
