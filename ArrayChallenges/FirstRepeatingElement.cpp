// First Repeating Element 
/*
Problem Statement:
Given an array arr[] of size N. The task is to find the 
first repeating element in the array of integers, i.e.,
an element that occurs more than once and whose index of first occurrence
is smallest.
Example:
Input:
7
1 5 3 4 3 5 6
Output:
2
Explanation:
5 is appearing twice and its first appearance is at the index 2
which is less than 3 whose first occurring index is 3.
*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int FirstRepeatingElement(int a[], int n)
{
    const int N = 1e6+2;
    short idx[N];
    short minidx = SHRT_MAX;
    for(int i=0;i<N;i++)
    {
        idx[i] = -1;
    }
    for(int i=0;i<n;i++)
    {
        if(idx[a[i]] != -1)
        {
            minidx = min(minidx, idx[a[i]]);
        }
        else
        {
            idx[a[i]] = i;
        }
    }
    if(minidx != INT_MAX)
    {
        return minidx+1;
    }
    return -1;
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
    cout<<FirstRepeatingElement(a,n);
    return 0;
}
