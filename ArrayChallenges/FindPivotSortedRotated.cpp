/*
Problem - Find the pivot element index in the sorted rotated array.
where for this question pivot element is the element from which the array is rotated.
Example -
Input - {3,4,5,1,2}
Output - 3

Approach - 
We can use binary search.
3 4 5 make a line - 1st line 
and 1 2 make another line - 2nd line

if arr[mid] >= arr[0] means our mid is in 1st line but our pivot is present on 2nd line
so we need to increase the start
if arr[mid] < arr[0] means our mid is in 2nd line and our pivot is also present on 1st line
so we need to decrease the end.

*/

#include<bits/stdc++.h>
using namespace std;

int FindPivot(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;

    while(start<end)
    {
        if(arr[mid]>=arr[0])
        {
            start = mid+1;
        }
        else
        {
            end = mid;
        }
        mid = start+(end-start)/2;
    }
    return start; // we can return the end also. Both indicate the same element.
}

int FindPivotCompleteBinarySearch(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;

    while(start<=end)
    {
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
        {
            return mid;
        }
        else if(arr[mid]>arr[mid-1] && (arr[mid]<arr[mid+1] || arr[mid]>arr[mid+1]))
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
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
    cout<<FindPivot(arr,n)<<endl;
    cout<<FindPivotCompleteBinarySearch(arr,n);
    return 0;
}