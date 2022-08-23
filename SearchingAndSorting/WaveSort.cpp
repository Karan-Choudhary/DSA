/*
Wave Sort - We need to arrange the array in a wave form.
Explanation- 
Every alternate element is smaller than it's adjacent element.
arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=arr[5]<=arr[6]>=arr[7]<=arr[8]


Approach - 
-> We take alternate elements and compare it with
1. it's left element
if left element is greater than selected element, we swap them.
2. it's right element
if right element is greater than selected element, we swap them.
-> Then we take a jump of 2.

Time Complexity- 
Best Case - O(n)
Average Case - O(n)
Worst Case - O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void WaveSort(int arr[], int n)
{
    for(int i=1;i<n-1;i+=2)
    {
        if(arr[i-1]<arr[i])
        {
            swap(arr[i-1],arr[i]);
        }
        if(arr[i+1]<arr[i] && i<=n-2)
        {
            swap(arr[i+1],arr[i]);
        }
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
    WaveSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}