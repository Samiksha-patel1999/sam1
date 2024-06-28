
//MERGE SORT USIN RECUIRSION BY USING SINGLE ARRAY//
#include<iostream>
using namespace std;
int merge(int a[],int low, int high, int mid)
{
    int n1=mid-low+1;
    int n2=high-mid;

    int arr[n1];
    int brr[n2];

    for (int  i = 0; i < n1; i++)
    {
        arr[i]=a[low+i];
    }
    for (int i = 0; i < n2; i++)
    {
        brr[i]=a[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=low;
    while (i<n1 && j<n2)
    {
        if (arr[i]<brr[j])
        {
            a[k]=arr[i];
            k++;
            i++;
        }
        else{
            a[k]=brr[j];
            k++;
            j++;
        }
    }
    while (i<n1)
    {
    a[k]=arr[i];
    k++;
    i++;
    }
    while (j<n2)
    {
        a[k]=brr[j];
        k++;
        j++;
    }
}
    
    int mergesort(int a[], int low, int high)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        mergesort(a, low, mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    
}

int main()
{
 int i,n;
 cout<<"enter no of elements in array"<<endl;
 cin>>n;
 int arr[n];
 for ( i = 0; i < n; i++)
 {
    cout<<"enter element:"<<endl;
    cin>>arr[i];
}
mergesort(arr,0,n-1);
cout<<"sorted data:"<<endl;
for ( i = 0; i < n; i++)
{
    cout<< arr[i];
    
}
 return 0;
}