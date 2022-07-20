/*
Problem - Find the maximum subarray sum using sliding window

For a given array and integers K and X, find the maximum sum 
subarray of size K and having sum less than X.
*/


#include<bits/stdc++.h>
using namespace std;

int MaxSumSlidingWindows(int arr[], int n, int k, int x)
{
    int sum = 0;
    int ans = 0;
    for(int i=0;i<k;i++)
    {
        sum += arr[i];
    }
    if(sum<x) ans = sum;
    for(int i=k;i<n;i++)
    {
        sum = sum-arr[i-k]+arr[i];
        if(sum<x) ans = max(ans,sum);
    }
    return ans;
}

int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<MaxSumSlidingWindows(a,n,k,x);

    return 0;
}
