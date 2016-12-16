#include <isotream>
using namespace std;

typedef struct 
{
	int weight ;
	int parent,lchild,rchild;
}HTNode;
typedef HTNode * HuffmanTree;


void InitHuffmanTree(HuffmanTree & HT, int m)
{
	int i;
	HT = new HTNode[m];
	for (i = 0 ; i < m ; i++)
	{
		HT[i].weight = 0;
		HT[i].parent = -1;
		HT[i].lchild = -1;
		Ht[i].rchild = -1;
	}
}

void selectmin(HuffmanTree & HT , int n , int & min1 , int & min2)
{
	typedef struct  
       {  
              int NewWeight;//存储权  
              int p;//存储该结点所在的位置  
       }TempNode,*TempTree;  
    TempTree TT  = new TempNode[n];
    int i,j = 0;
    for (i = 0 ; i < n ; i++)
    {
    	if(HT[i].parent == -1 && HT[i].weight !=0)
         {
         	TT[j].NewWeight = HT[i].weight;
         	TT[j].p = i;
         	j++;
         }
    }

    int m1 = 0 , m2 = 0;
    for(i=0;i<j;i++)  
       {  
              if(TT[i].NewWeight < TT[m1].NewWeight)

                     m1=i;  
       }  
       for(i=0;i<j;i++)  
       {  
              if(m1 == m2)  
                  m2++;//当m1在第一个位置的时候，m2向后移一位  
              if(TT[i].NewWeight <= TT[m2].NewWeight && i!=m1)//此处取到相等，是让在结点中有相同的权值的时候，  
                  m2=i;  
       }  
   
       min1 = TT[m1].p;  
       min2 = TT[m2].p;   

}


void CreateHaffmanTree(HuffmanTree&HT,int n)  
{  
       int i;  
       int m;  
       int min1 , min2;  
       if(n <= 1)  
              cout<<"ParameterError!";  
       m = 2 * n - 1;//哈夫曼树中结点的个数  
        
       InitHuffmanTree(HT,m);  
   
       for(i = 0;i < n;i++)  
       {  
              cin>>HT[i].weight;  
       }  
   
       for(i = n;i < m;i++)  
       {  
              SelectMin(HT,i,min1,min2);  
              HT[min1].parent = i;  
              HT[min2].parent = i;  
              HT[i].lchild = min1;  
              HT[i].rchild = min2;  
              HT[i].weight = HT[min1].weight+HT[min2].weight;  
               
              cout<<min1<<""<<min2<<endl;  
       }  
}  


typedef  struct  
{
	char ch;
	char bits[10]
}CodeNode;


typedef CodeNode * HuffmanTree;

void CreateHaffmanCode( HuffmanTree & HT, HuffmanCode & Hc, int n);
{
	int i , start , c , p;  
    char * cd;  
    char q;  
    HC = new CodeNode[n];  
    cd = new char[n];  
    cd [ n - 1 ] = '/0';
   
    for ( i = 0 ; i < n ;i++)
    {
    	cin >> q;
    	HC[i].ch = q;
    	start = n -1;
    	c = i ;
    	while ((p = HT[c].parent) >= 0)
    	{
    		--start;
    		cd[ start ] = (HT[p].lchild == c )? '0':'1';
    		c = p;
    	}
    	strcpy(HC[i].bits , & cd [start]);
    }

    delete  cd;  
}



