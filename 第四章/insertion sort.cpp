#include <iostream>
#include <iomanip>
using namespace std;

void swap ( int & x , int & y)
{
    int temp = x;
    x = y;
    y = temp;
}


void insertion( int a[] , int sz )
{
    for ( int i = 1 ; i < sz ; i++ )
    {
         int j = i ;
         while ( j > 0 && (a[j] < a[j-1]))
         {
             swap( a[j] , a[j-1]);
             j--;
         }
         cout << endl;
         for ( int k = 0 ; k < sz ; k++ )
         cout << a[k] << endl;
    }
}