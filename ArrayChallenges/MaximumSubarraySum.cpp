// Maximum Subarray Sum:
/*
Find the subarray in an array which as maximum sum

Optimized Approach:
Kadane's Algorithm
It says that look for all positive contiguous segments of the array.
And keep track of maximum sum contiguous segment among all positive segments.
Each time we get a positive sum compare it with maximum sum so far and 
update maximum sum of it is greater than maximum sum so far.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void MaximumSubarraySum(int a[], int n)
{
    int max_sum=INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            sum += a[j];
            max_sum = max(max_sum,sum);
        }
        sum = 0;
    }
    cout<<max_sum;
}

void MaximumSubarraySumKadane(int a[], int n)
{
    int currSum = 0;
    int max_sum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(currSum+a[i]<0)
        {
            currSum = 0;
        }
        else
        {
            currSum += a[i];
        }
        max_sum = max(max_sum,currSum);
    }
    cout<<max_sum;
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
    // MaximumSubarraySum(a,n);
    MaximumSubarraySumKadane(a,n);
    return 0;
}