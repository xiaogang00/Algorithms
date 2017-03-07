#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int factor( int n )
{
    int s = 1;
    for (int i = 1 ; i <= n ; i++)
        s = s *i;
    return s;
}

void swap( int &a , int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Arrange(int A[],int start,int step,int n,int m,int Max,int *path,int **dist)  
{  
    if(n < m)    m = n;//从n个数中最多可以求n个数的全排列  
    int len = 0 ;
    int count = 0;
    int mindist = 10000;
    if (step == m)//穷举求最小的路径并存到数组中  
    {  
        len=0;  
        count++;  
        for (int i = 0; i < m; i++)//计算当前序列的路径长度
        {  
            if(i < m-1)
                len = len+dist[A[i]][A[i+1]];  
            else  
                len = len+dist[A[i]][A[0]];  
            cout<<A[i]<<" " ;              
        }  
        if(len < mindist)//更新最短路径  
        {  
            mindist = len;  
            int i = 0 ;
            for(i = 0;i < m; i++)  
                path[i] = A[i];  
            path[i] = A[0];  
        }  
        cout<<endl;  
    }  
    if(count == Max)//做完之后输出最短路径及其长度  
    {  
        cout<<"最短路径为："<< mindist << endl;   
        cout<<"旅行路线为：";  
          
        for(int i = 0;i <= m; i++)  
        {  
            char name [4] = {'a','b','c','d'};            
            if(i != 0 && path[i] == 0)//终点  
                cout<<" ("<<name[path[i]]<<")";  
            else//非终点  
                cout<<" ("<<name[path[i]]<<") "<<"--"<<dist[path[i]][path[i+1]]<<"-->";  
        }  
        cout<<endl;  
    }  
    else   
    {  
    //第j个数分别与它后面的数字交换就能得到新的排列  
  
        for (int j = start; j < n; j++)  
        {  
            swap(A[step],A[j]);  
            Arrange(A,start+1,step+1,n,m,Max,path,dist);  
            //递归调用来实现所有的组合
            swap(A[j],A[step]);  
        }  
    }  
}  



