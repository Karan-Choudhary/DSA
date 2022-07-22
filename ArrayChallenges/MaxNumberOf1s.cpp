/*
Problem - Given an array A of 0s and 1s, we may change up to
K values from 0 to 1.
Return the length of the longest(contiguous) subarray that contains
only 1s.

Example1:
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1,1]

Example2:
Input: A = [1,1,1,0,1,0,1,1,1,1,0], K=2
Output: 10
Explanation:
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0]

Approach: Sliding Window Concept
1. We can use two pointer approach(j=0 and i=0).
2. take a vairable zerocount=0.
3. traverse from j=0 to n-1.
4. if element is 0 then increment zerocount.
5. check if zerocount is greater than k.
if yes -> increase i until zerocount is less than k. along with i++.
6. store possible ans in max_ans as maximum of max_ans and j-i+1.
*/

#include<bits/stdc++.h>
using namespace std;

int MaximumOnes(int arr[], int n, int k)
{
    int ans=0;
    int zerocount=0;
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==0) zerocount++;
        while(zerocount>k)
        {
            if(arr[i]==0) zerocount--;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<MaximumOnes(arr,n,k);
    return 0;
}