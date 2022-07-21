/*
Problem - Count the inversions in the given array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example - {3,5,6,9,1,2,7,8}
Output - 10

Explanation -
(3,1),(3,2),(5,1),(5,2),(6,1),(6,2),(9,1),(9,2),(9,7),(9,8)

Optimized Approach - 
1. We can use merge sort approach.
2. In merge Sort while merging, we can count the inversions.
suppose in merge we have 
{3,5,6,9} and {1,2,7,8}
then 
if 3 < 1 it means the element after 3 are also greater than 1.
that means we need to count the inversion of element 3 with 1 
as well as the inversions of elements after 3 with 1.
*/

#include<bits/stdc++.h>
using namespace std;

long long Merge(int arr[], int l, int mid, int r)
{
    long long inversionCount = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++)
    {
        arr1[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        arr2[i] = arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            inversionCount += n1-i;
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return inversionCount;
}

long long CountInversion(int arr[], int l, int r)
{
    long long inversion = 0;
    if(l<r)
    {
        int mid = (l+r)/2;
        inversion += CountInversion(arr,l,mid);
        inversion += CountInversion(arr,mid+1,r);
        inversion += Merge(arr,l,mid,r);
    }
    return inversion;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<CountInversion(arr,0,n-1);
    return 0;
}