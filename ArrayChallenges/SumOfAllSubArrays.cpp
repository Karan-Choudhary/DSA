// Sum of all SubArrays
// Given an array a[] of size n. Output sum of each subarray
// of the given array.

#include<iostream>
using namespace std;

void sumSubArray(int a[], int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            sum += a[j];
            cout<<sum<<" ";
        }
        sum = 0;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sumSubArray(a,n);
    return 0;
}