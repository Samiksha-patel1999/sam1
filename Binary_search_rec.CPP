/*BINARY SEARCH THROUGH RECURSIVE APPROACH*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;



int Binary_search(int a[],int low, int high, int x)     //declared array,lowest idex,highest index,element to be found//
{    
  if (high==low)
  {
    if(x==a[low])
    return low;
    else
    return 0;
  }
  else
  {
    int mid=(high+low)/2;
    if(x==a[mid])
    return mid;
    else if(x<a[mid])
    return Binary_search(a,low,mid-1,x);
    else return Binary_search(a, mid+1, high, x);
  }
}

int main()
{
    int n=10;
   int x;
   int a[10];

   cout<<"Display the array:"<<endl;
   for (int i = 0; i < n; i++)
   {
     cout<<"arr["<<i<<"]=";
     cin>>a[i];
   }
   cout<<"element to be searched:";
   cin>>x;
   cout<<Binary_search(a,0,n-1,x);
    return -1;
}


