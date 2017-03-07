#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define VertexNum 100
#define MAXV   100

typedef struct          
{        
    char vertex[VertexNum];                                //顶点表         
    int edges[VertexNum][VertexNum];                       //邻接矩阵,可看做边表         
    int  v , e;                                               //图中当前的顶点数和边数         
}MGraph; 

void Floyd(MGraph g)
{
    int A[MAXV][MAXV];
    int path[MAXV][MAXV];
    int i,j,k,n=g.v;
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       {
             A[i][j]=g.edges[i][j];
             path[i][j] = -1;
       }
     for ( k = 0 ; k < n ; k++ )
     { 
          for(i = 0;i < n; i++)
              for(j=0;j<n;j++)  //依旧三层循环来实现
                if( A[i][j] > (A[i][k]+A[k][j]) )
                 {
                     A[i][j] = A[i][k] + A[k][j];
                     path[i][j] = k ;
                 } 
     } 
} 


int main ( void )
{
    MGraph g;
    Floyd( g );
    return 0;
}