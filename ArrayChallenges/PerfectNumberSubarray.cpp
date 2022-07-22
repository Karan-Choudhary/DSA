/*
Problem - For a given array and an integer K, find the maximum
perfect numbers in a subarray of size K.

Perfect number is a number if it is equal to the sum of its
proper divisors(positive divisors) except for the number itself.
Example: number = 6, proper divisors = 1,2,3
1+2+3 = 6
So, 6 is a perfect number.

Approach:
1. Convert the given array into a binary array with values
0 and 1 only.
    a. Traverse the array and if the number at index i is a perfect 
    number then replace value at ith index with 1 else 0.
2. Initialize a variable max_count = 0.
3. Traverse the binary array from left to right.
    a. If the value at index i is 1 then increment max_count.
    b. If max_count is greater than K then decrement max_count.
    c. If max_count is equal to K then increment max_count.
4. Return max_count.

*/

#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int n)
{
    int sum = 1;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            sum += i;
            if(i*i != n)
                sum += n/i;
        }
    }
    return sum == n;
}

int PerfectNumberSubarray(vector<int> arr, int n, int k)
{
    int max_count = 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(isPerfect(arr[i]))
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    for(int i=0;i<k;i++)
    {
        if(arr[i] == 1)
            count++;
    }
    max_count = count;
    for(int i=k;i<n;i++)
    {
        count = count - arr[i-k] + arr[i];
        max_count = max(max_count, count);
    }
    return max_count;
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

    cout<<PerfectNumberSubarray(arr, n, k);

    return 0;

}