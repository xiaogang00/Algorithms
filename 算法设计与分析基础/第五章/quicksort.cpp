#include<iostream>  
using namespace std;  

void quickSort(int a[], int l, int r);  

int main()  
{  
    int array[]={34,65,12,43,67,5,78,10,3,70};
    int k = 0;  
    int len = sizeof(array)/sizeof(int);  
    int a = 0;
    
    cout<<"The orginal arrayare:"<<endl;  
    for(k=0;k<len;k++)  
        cout<<array[k]<<",";  
    cout<<endl;  
    quickSort(array,0,len-1);  
    cout<<"The sorted arrayare:"<<endl;  
    for(k=0;k<len;k++) 
        cout<<array[k]<<",";  
    cout<<endl;  
    system("pause");  
    return 0;  
}  

void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                swap(s[i] , s[j]);
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // 递归调用  
        quickSort(s, i + 1, r);  
    }  
}  