#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define n 100
void rough(int x[],int y[],int N)
{
   int  a,b,c;
   int Y,i,j,k,count=0;
   int count1=0,count2=0;

  for(i=0;i<N-1;i++)
    for(j=i+1;j<N;j++)
     {    		
        a=y[j]-y[i];
        b=x[i]-x[j];
        c=x[i]*y[j]-y[i]*x[j];
        for(k=0;k<N;k++)
          {
            Y=a*x[k]+b*y[k]-c;
            if(Y>=0) count1++;
            if(Y<=0) count2++;
          }   
         if((count1==(N))||(count2==(N)))

          { 
          printf("(%d,%d),(%d,%d)\n",x[i],y[i],x[j],y[j]);
          }
                   count1=0;
                   count2=0;    
     }

}

int main()
{  
 int x[n],y[n];
 int i,N;
 for(i=0;i<N;i++)
  {
	x[i]=rand()%200+100;
  y[i]=rand()%200+100;
  }
  rough(x,y,N);
  return 0;
}