/*
Problem - Find the unique number in an array where all numbers
expect one, are present twice.

Example - 
Input - {2,4,6,3,4,6,2}
Output - 3

Optimized Approach - 
1. We can use XOR operation to find the unique number.
If we do the XOR operation between same numbers, we get 0.
Example:
(0110) XOR (0110) = 0000
*/

#include<bits/stdc++.h>
using namespace std;

int UniqueNumber(int arr[], int n)
{
    // USING SORTING
    // sort(arr,arr+n);
    // for(int i=0;i<n;i+=2)
    // {
    //     if(arr[i] ^ arr[i+1])
    //     {
    //         return arr[i];
    //     }
    // }

    // USING XOR_SUM
    int xor_sum = 0;
    for(int i=0;i<n;i++)
    {
        xor_sum ^= arr[i];
    }
    return xor_sum;
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

    cout<<UniqueNumber(arr,n);
    // (3 XOR 4) XOR 4 = 3
    // (3 XOR 4) XOR 3 = 4

    return 0;
}