/*
Problem - DNF Sort or Dutch National Flag Problem or 0,1,2 Sort
In a given array, all the elements are either 0, 1 or 2.

Time Complexity - 
In each operation, either mid get incremented or high get decremented
So the time complexity is O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void DNFSort(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        switch(arr[mid])
        {
            case 0:
                swap(arr[low],arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[high],arr[mid]);
                high--;
                break;
        }
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
    DNFSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
