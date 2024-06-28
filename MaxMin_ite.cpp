//Iterative method of finding maximum and minimum//
#include<iostream>
using namespace std;
int straightmaxmin(int a[], int n, int max, int min)
{
    max=min=a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
        /*else if (a[i]<min)
        {
            min=a[i];
        }*/
        
    }
    cout<<max;
    
    /*for (int i = 1; i < n; i++)
    {
        if (a[i]<min)
        {
            min=a[i];
        }
        /*else if (a[i]<min)
        {
            min=a[i];
        }
        
    }
    cout<<min;*/
}


int main()
{
    int a[10]={40,60,30,10,70,100,80,90,20,50};
    
    int max, min;
    cout<<straightmaxmin(a,10,max,min);
}
