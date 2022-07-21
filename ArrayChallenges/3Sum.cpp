/*
Problem - 3 Sum
Given an array and a value, find if there exists three numbers whose sum is 
equal to the given value.

Example:
Input: 
n=6 target=24
arr[] = {12, 3,7, 1, 6, 9}
Output: True

Optimized Approach:
1. Sort the array.
2. Fix one element
3. apply two pointer on rest of the array.

Time Complexity:
Time Complexity for sorting: O(nlog(n))
Iterating each element and applying two pointer approach
to rest of the array: O(n*n)
Total time complexity: O(nlog(n) + n*n) = O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

bool Find3Sum(int arr[], int n, int target)
{
    sort(arr,arr+n);
    for(int i=0;i<=n-2;i++)
    {
        int j=i+1;
        int k = n-1;
        int findSum = target-arr[i];
        while(j<k)
        {
            if(findSum == (arr[j]+arr[k]))
            {
                return true;
            }
            else if(findSum < (arr[j]+arr[k]))
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<Find3Sum(arr,n,target);
    return 0;
}