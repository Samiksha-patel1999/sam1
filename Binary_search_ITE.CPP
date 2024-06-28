/*BINARY SEARCH BY ITERATIVE APPROACH*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int x) // define independent function having array, no of elements in array & element to be searched//
{
 int low= 0;
 int high = n;
 int mid;
 while (low<=high)
 {
    mid =(low+high)/2;
    
    if(arr[mid] == x)
    return mid;
    
    else if(x > arr[mid])
    low = mid+1;

    else 
    high = mid-1;
}
 return 0;
} 

int main()
{
   int n =10;
   int x;
   int arr[10];

   cout<<"display the array:"<<endl;
   for (int i = 0; i < n; i++)
   {
     cout<<"arr["<<i<<"]=";
     cin>>arr[i];
   }
   cout<<"element to be searched:"<<endl;
   cin>>x;
   cout<<BinarySearch(arr,n,x);
   return 0;

}

