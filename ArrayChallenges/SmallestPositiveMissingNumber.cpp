// Smallest Positive Missing Number
/* 
Problem Statement:
You are given an array arr[] of N integers including 0.
The task is to find the smallest positive number missing from the array.
Example:
Input:
N = 6
arr[] = {0, -9, 1, 3, -4, 5}
Output:
2
Explanation:
Here the first positive missing number is 2

Optimized Approach:
Build a boolean check[] array that will depict if any element
x is present in array or not
Iterate over the array and mark non-negative a[i] as True.
*/ 

#include<bits/stdc++.h>
using namespace std;

int SmallestPositiveMissingNumber(int a[], int n)
{
    int ans=-1;
    const int N = 1e6+2;
    bool check[N];
    for(int i=0;i<N;i++)
    {
        check[i] = false;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            check[a[i]] = true;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(!check[i])
        {
            ans = i;
            break;
        }
    }
    return ans;
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
    cout<<SmallestPositiveMissingNumber(a,n);
    return 0;
}