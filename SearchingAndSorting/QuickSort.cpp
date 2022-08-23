/*
Quick Sort - 
Approach - 
It follows Divide and Conquer approach.
Choose an element and put it in its correct position.
Then sort the remaining elements.
(Note- Correct is the position where all the element before it
are less than the choosen element and all the element after the 
choose element are greater than the choosen element.)

Time Complexity - 
Best Case - O(nlogn)
Average Case - O(nlogn)
Worst Case - O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int i=l-1;
    int j=l;
    for(;j<r;j++)
    {
        if(arr[j]<arr[r])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int arr[],int l, int r)
{
    if(l<r)
    {
        int pivot = partition(arr,l,r);
        quickSort(arr,l,pivot-1);
        quickSort(arr,pivot+1,r);
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
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}