// Binary Search
// Time complexity: O(log n)

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int s=0, e=n;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return -1;
}

int main()
{
    int n,ele;
    cin>>n;
    int arr[n];
    cin>>ele;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<binarySearch(arr,n,ele);

    return 0;
}