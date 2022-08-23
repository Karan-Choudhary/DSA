/*
Problem - Perform merge sort
*/

#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
    int temp1[mid-l+1];
    int temp2[r-mid];
    int n1=mid-l+1;
    int n2=r-mid;

    for(int i=0;i<n1;i++)
    {
        temp1[i] = arr[l+i];
    }

    for(int i=0;i<n2;i++)
    {
        temp2[i] = arr[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(temp1[i]<=temp2[j])
        {
            arr[k] = temp1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = temp2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);

        Merge(arr, l, mid, r);
    }
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
    MergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}