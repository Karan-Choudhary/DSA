// Maximum Circular Subarray Sum
/*
Approach:
we have 2 cases:
Case1: {-1,4,-6,7,5,-4}
In this case our maximum sum is 12 and we don't have any need to 
go circular i.e. we don't have any need of wrapping
Case2: {4, -4, 6, -6, 10, -11, 12}
In this case our maximum sum is 22 and the elements which makes this sum are
4, -4, 6, -6, 10, 12. In order to achieve that we need to go circular i.e., we need 
to wrap.

Let those element which are contributing to the maximum sum are known as contributing elements
and those which are not contributing to the maximum sum are known as non contributing elements.
Note: If our **contributing** elements are **wrapping** then our **non-contributing** elements are **non-wrapping.** and vice-versa.
and If our **non-contributing** elements are **wrapping** then our **contributing** elements are **non-wrapping.** and vice-versa.

In Case 1, 
Our non-contributing elements are wrapping and contributing elements are non-wrapping
So, we can directly use Kadane's Algorithm 

And in Case 2:
Our contributing elements are wrapping and non-contributing elements are non-wrapping
So our maximum sum will be:
Max Circular subarray sum = Total sum of array - (-Sum of non-contributing elements)
We can find sum of non-contributing elements using Kadane's Algorithm.

Sum of Non-contributing elements:
1. Reverse the signs of the original array.
2. Find the maximum subarray sum of modified array 
using Kadane's algorithm or any other algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

int KadaneAlgorithm(int a[], int n)
{
    int sum = 0;
    int max_sum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        if(sum<0)
        {
            sum = 0;
        }
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}

int MaximumCircularSubarraySum(int a[], int n)
{
    int TotalSum = 0;
    int Non_Contributing_Sum = 0;

    // Loop for reversing and total sum
    for(int i=0;i<n;i++)
    {
        TotalSum += a[i];
        a[i] = -a[i];
    }
    Non_Contributing_Sum = KadaneAlgorithm(a,n);
    return TotalSum + Non_Contributing_Sum;
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
    int nonWrapSum = KadaneAlgorithm(a,n);
    int WrapSum = MaximumCircularSubarraySum(a,n);
    cout<<max(nonWrapSum,WrapSum);
    return 0;
}