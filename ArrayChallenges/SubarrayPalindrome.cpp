/*
Problem - For a given array and an integer K, 
check if any subarray of size K exists in the array
such that concatenation of elements form a palindrome.

Approach - 
1. Store concatenation of initial K elements
2. Iterate over the array and start deleting elements 
from te start and adding elements from the end.
3. At each step, check if concatenation is palindrome or not.

Time Complexity - O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    int temp=num;
    int rev=0;
    while(num>0)
    {
        rev = rev*10 + num%10;
        num = num/10;
    }
    return (rev==temp);
}

int findPalindromeSubarray(vector<int> arr, int n, int k)
{
    int num = 0;
    for(int i=0;i<k;i++)
    {
        num = num*10 + arr[i];
    }

    if(isPalindrome(num))
    {
        return 0;
    }

    for(int i=k;i<n;i++)
    {
        num = (num%(int)pow(10,k-1))*10+arr[i];
        if(isPalindrome(num))
        {
            return i-k+1;
        }
    }

    return -1;

}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<findPalindromeSubarray(arr, n, k);

    return 0;
}