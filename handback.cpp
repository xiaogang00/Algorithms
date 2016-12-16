#include <iostream>  
#define N 5  
#define ST 10  
using namespace std;  
  
int main() {  
        //给定n个重量，价值为不同的个物品和容量为c的背包，求这些物品中一个最有的价值的子集  
        int a[N]={2,1,3,4,7};  
        int b[N]={2,5,4,1,2};  
        int sum1=0;//sum1表示最终的价值  
        for(int i = 0 ;i < N ;i++)//这是对每次的  
        {  
            int STS=0;//石头的总个数  
            int QS=0;//价值的总个数  
            for(int j=0;j<N;j++)  
            {  
                if(STS+a[i]<ST)//如果石头没有放完，则继续放  
                {  
                    cout<<"石头个数："<<a[j]<<"    ";  
                    cout<<"对应的价值为："<<a[j]*b[j]<<endl;  
                    STS+=a[j];  
                    QS+=a[j]*b[j];  
                }//否则则不进行  
            }//直到这个循环结束后就出来求出总的价值  
            cout<<"第"<<i+1<<"次的总价值为："<<QS<<endl;  
            cout<<endl;  
            if(QS>sum1)  
            {  
                sum1=QS;  
            }  
        }  
        cout<<"蛮力法背包最大的价值为："<<sum1<<endl;  
        return 0;  
}  