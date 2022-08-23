/*
CountSort - 
Approach - 
Find the count of every element in the array.
Calculate the position of each element in the sorted array.

First store the count of every element in the array.
Modify the count array such that count[i] contains the sum of count[0] to count[i].
Traverse the original array from backward and do:
a. if the element value in the original array is A then
check the value of modified count array at the index of A. 
and decrement the value of modified count array at the index of A let suppose it comes out B.
b. store the A at the position B.

Time Complexit - 
1. First we create an array of appropriate range, Time: O(max(Ai))
2. Fill the frequencies of each element, Time: O(N)
3. Iterate the frequency array, Time: O(max(Ai))
Total Time Complexity: 
***********O(max(N,(Ai)))***********

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> CountSort(int arr[], int n)
{
    int maxEle = *max_element(arr,arr+n);
    int count[maxEle+1]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<maxEle+1;i++)
    {
        count[i]+=count[i-1];
    }
    vector<int> sortedArr(n);
    for(int i=n-1;i>=0;i--)
    {
        sortedArr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    return sortedArr;
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
    
    vector<int> result = CountSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}