#include<stdio.h>  
#include <stdlib.h>  
  
#define MAX_SIZE 10001  
struct Point{  
    int x,y;  
};  
  
// 按照x的从小到大进行排序，X相同按照Y从小到大排序  
int CmpByX(const void *left, const void *right);  
  
//处理point[first]->point[final]射线左侧的点  
void DealWithLeft(int first,int final,struct Point point[MAX_SIZE],int mark[MAX_SIZE]);  
  
int ConvexHull(void)  
{  
    int n,i,j;  
    struct Point p[MAX_SIZE];  
    int mark[MAX_SIZE];  
  
    freopen("input.txt", "r", stdin);  
    freopen("outputch.txt","w",stdout);  
    while(scanf("%d", &n) != EOF)  
    {  
        for(i = 0; i < n; i++)  
        {  
            scanf("%d%d",&p[i].x,&p[i].y);  
            mark[i]=0;  
        }  
  
        //start = GetTickCount();  
        //给数组排序，按x从小到大  
        qsort(p, n, sizeof(struct Point), CmpByX);  
        mark[0] = 1;  
        mark[n-1] = 1;  
        //获取convex数组，存放所有结果顶点  
        DealWithLeft(0,n - 1,p,mark);   //处理point[0]->point[14]射线左边的点  
        DealWithLeft(n - 1,0,p,mark);   //处理point[14]->point[0]射线右边的点  
        printf("结果集：\n");  
        j=0;  
        for(i=0;i<n;i++)  
        {  
            if(mark[i])  
            {  
                printf("%d,%d\t",p[i].x,p[i].y);  
                j++;  
                if(j%5==0)  printf("\n");  
            }  
        }  
        printf("\n");  
    }  
    return 0;  
}  
  
  
// 按照x的从小到大进行排序，X相同按照Y从小到大排序  
int CmpByX(const void *left, const void *right)  
{  
    struct Point *leftPoint = (struct Point *)left;  
    struct Point *rightPoint = (struct Point *)right;  
    if(leftPoint->x != rightPoint->x)  
    {  
        return (leftPoint->x - rightPoint->x);  
    }  
    else  
    {  
        return (leftPoint->y - rightPoint->y);  
    }  
}  
  
  
//处理point[first]->point[final]射线左侧的点  
void DealWithLeft(int first, int final, struct Point point[MAX_SIZE], int mark[MAX_SIZE])  
{  
    int max = 0, index = -1;  
    int i = first;  
    if(first < final)  //point[first]->point[final]射线左侧  
    {  
        for(i = first ; i < final; i++)  
        {  
            int x1 = point[first].x, y1 = point[first].y;  
            int x2 = point[final].x, y2 = point[final].y;  
            int x3 = point[i].x;  
            int y3 = point[i].y;  
  
            //设A（x1,y1）,B（x2,y2）,C（x3,y3）在坐标系中中顺序为三点按逆时针排列,面积为  
                //S=1/2[(x1y2-x2y1)+(x2y3-x3y2)+(x3y1-x1y3)]  
            int compute = x1 * y2 + x3 * y1 + x2 * y3 - x3 * y2 - x2 * y1 - x1 * y3;  
            if(compute > max)  
            {  
                max = compute;  
                index = i;  
            }  
        }  
    }  
    else  
    {  
        for(i = final ; i >= 0; i--)//point[final]->point[first]射线左侧  
        {  
            int x1 = point[first].x,y1 = point[first].y;  
            int x2 = point[final].x,y2 = point[final].y;  
            int x3 = point[i].x,y3 = point[i].y;  
  
            int compute = x1 * y2 + x3 * y1 + x2 * y3 - x3 * y2 - x2 * y1 - x1 * y3;  
            if(compute > max)  
            {  
                max = compute;  
                index = i;  
            }  
        }  
    }  
  
    if(index!=-1)   
    //取到point[index]（即最高点） ，这个点与point[final]、point[first]构成的三角形面积最大  
    {   //index 这个点就可以确定为凸包的顶点 
        mark[index] = 1;  
        DealWithLeft(first,index,point,mark);  
        DealWithLeft(index,final,point,mark);  
    }  
}  