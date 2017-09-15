#ifndef HANDLE_H
#define HANDLE_H
#define INF 10000
enum COLOR{WHITE,GRAY,BLACK}; 
/*********************************
BFS
**********************************/
void print(struct node* (parent[]),int s,int v);
int bfs(int s,struct node* (v[N]),struct node* (parent[]),int distance[]);
int handle_bfs(char *filename,int s); 
/*********************************
DFS
*********************************/
int handle_dfs(char *filename);
int dfs(struct node* (v[]),int d[],int f[],int parent[]);
void dfs_visit(int &time,int i,struct node* (v[]),int d[],int f[],int parent[],COLOR color[]);
void print_dfs(struct node* (v[]),int parent[],int d[],int f[]);
#endif
