/*
Problem - Generate all possible subsets of a given set.

Example -
Input - {a,b,c}
Output - {{},{c},{b},{b,c},{a},{a,c},{a,b},{a,b,c}}

Optimized Approach -
1. If we have n number of elements in our set, then we can represent them
with n bits.
If an element comes in the set, we can represent it by SET BIT i.e., 1.
if an element does not come in the set, we can represent it by CLEAR BIT i.e., 0.
** If we have set of n elements then, the number of subsets will be (2^n)-1
                        abc
{}                     000              0
{c}                   001               1
{b}                   010               2
{b,c}                011                3
{a}                   100                4
{a,c}                101                5
{a,b}                110                6
{a,b,c}             111                 7

2. Apply a loop which would be running from 0 to 2^n-1.
3. For each iteration, check where-ever the bit is SET BIT, the corresponding element will be included in the subset.

***NOTE***
2^n can be written as 1<<n

*/

#include<bits/stdc++.h>
using namespace std;

void AllSubsetsOfSet(int arr[], int n)
{
    for(int i=0;i<(1<<n);i++)
    {
         for(int j=0;j<n;j++)
         {
             if( i & (1<<j)) // check if the bits is SET or not at jth position
             {
                //  cout<<"i: "<<i<<" "<<endl;
                //  cout<<"j: "<<j<<" ";
                 cout<<arr[j]<<" ";
             }
         }
         cout<<endl;
    }
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

    AllSubsetsOfSet(arr,n);
    // cout<<(7&(1<<2))<<endl;
    return 0;
}