// SubArray with given sum
/*
Problem Statement:
Given an unsorted array A of size N of non-negative intergers,
find a continuous subarray which adds to a given number S.
Example:
Input:
N=5, S=12
A[] = {1, 2, 3, 7, 5}
Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12.

Optimized Approach:
Keep 2 pointers st and en, and a variable currSum sum from st to en.
increment en till currSum+a[en]>s.
increment st till currSum-a[st]<=s.
Time complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void SubArrayWithGivenSum(int a[], int n, int s)
{
    int i=0,j=0;
    int st=-1, en=-1;
    int currSum=0;
    while(j<n && currSum+a[j]<=s)
    {
        currSum+=a[j];
        j++;
    }
    if(currSum==s)
    {
        cout<<i+1<<" "<<j;
        return;
    }
    while(j<n)
    {
        currSum+=a[j];
        while(currSum>s)
        {
            currSum-=a[i];
            i++;
        }
        if(currSum==s)
        {
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en;
}

int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    SubArrayWithGivenSum(a,n,s);
    return 0;
}
