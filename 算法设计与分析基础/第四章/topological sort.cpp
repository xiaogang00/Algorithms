#include <iostream>
#include < fstream>
#include < stack > 

using namespace std;

#define Max_Vertex_Num 26
stack <int> s;
ifstream fin(" data.txt ");

typedef struct ArcNode
{
    int adjvex ; 
    struct ArcNode * nextarc;
    AreNode( )
    {
        nextarc = NULL;
    }
} ArcNode

typedef struct VNode
{
    int data;
    ArcNode * firstarc;
    VNode( ) { firstarc = 0; }
}VNode , AdjList[Max_Vertex_Num];

typedef struct 
{
    AdjList vertices;
    int vexnum , arcnum;
    int kind;
} ALGraph;

bool TopologicalSort( ALGraph G , int * indegree)
{
    int i , k ;
    for ( i = 1 ; i < G.vexnum + 1 ; i++)
    {
        if( !indegree[i])
        {
            s.push(i);
        }
    }
    int count = 0;
    ArcNode * p;
    while ( !s.empty())
    {
         i = s.top() ; 
         s.pop() ; 
         cout << G.vertices[i].data << "-->";
         count ++;
         for ( p = G.vertices[i].firstarc ; p ; p = p -> nextarc)
         {
             k = p->adjvex;
             indegree[k] -- ;
             if( ! indegree[k] )
                  s.push(k);
         }
    }
    if(count < G.vexnum)
       return false;
    return true;
}

