#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{

 int n_dim=0;
 cout<<"Input number of dimensions:";
 cin>>n_dim;

 char **array=new char*[n_dim];   
 char ch;                             

 for(int i=0;i<n_dim;i++)
 {
  array[i]=new char[n_dim];     
  for(int j=0;j<n_dim;j++)
  {
   cin>>ch;
   array[i][j]=ch;  //设立传递闭包所需要的图
  }
 }

 for(i=0;i<n_dim;i++)
  for(int j=0;j<n_dim;j++)
   for(int k=0;k<n_dim;k++)
    if(array[i][j]=='1'&&array[k][i]=='1')  //必须通过三层循环来实现
    array[k][j] = '1';
 cout<<"The trasitive closure of a relation R represented:"<<endl;

 for(i=0;i<n_dim;i++)
 {
   for ( int j = 0 ; j < n_dim ; j++)
        cout << array[i][j];
        cout << endl;
 }

}