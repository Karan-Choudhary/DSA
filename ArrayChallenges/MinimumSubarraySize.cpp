/*
Problem - For a given array and an integer X, find the minumum
subarray size for which sum>X.
*/

#include<bits/stdc++.h>
using namespace std;

int MinimumSubarraySize(int arr[], int n, int x)
{
    int sum = 0;
    int ans = INT_MAX;
    int start=0, i=0;
    while(i<n)
    {
        sum += arr[i];
        if(sum>=x)
        {
            while(start<n && sum>x)
            {
                if(i-start+1 < ans)
                {
                    ans = i-start+1;
                }
                sum -= arr[start];
                start++;
            }
        }
        i++;
    }   
    return ans;
}

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(MinimumSubarraySize(a,n,x)==INT_MAX)
    {
        cout<<"0";
    }
    else
    {
        cout<<MinimumSubarraySize(a,n,x);
    }

    return 0;
}