// Pair Sum Problem:
/*
Check if there exists two elements in an array such that their sum is equal
to given k.
Optimized Approach:
We can use two pointers to find the sum of two elements.
1. Sort the array in ascending order.
2. Given two pointers, one at the start and one at the end.
3. While start < end do:
3.1 If the sum of two pointers is greater than k, then move the end pointer to one position behind.
3.2 If the sum of two pointers is less than k, then move the start pointer to one position ahead.
3.3 If the sum of two pointers is equal to k, then print the pair and return.

Time complexity : O(n) if array is sorted and we are sorting array.
O(nlogn) if array is not sorted and we are sorting array.
*/

#include<bits/stdc++.h>
using namespace std;

bool CheckPairPresent(int a[], int n, int CheckSum)
{
    sort(a, a+n);
    int low = 0, high = n-1;
    while(low<high)
    {
        if(a[low] + a[high] == CheckSum)
        {
            return true;
        }
        else if(a[low] + a[high] < CheckSum)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}

int main()
{
    int n,CheckSum;
    cin>>n>>CheckSum;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout<<CheckPairPresent(a,n,CheckSum);
}