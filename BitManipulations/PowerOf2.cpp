/*
Problem - Power of two : Check if given number is power of 2 or not.
Input - number
Output - true or false

Optimized Approach -
1. Given a number n, we can find the n-1 number by flipping the right most set bit 
along with all the bits to its right.
Example: n = 8, n-1 = 7
6 = 1000 right most set bit is at the position 3
5 = 0111

2. Now do AND operation between n and n-1.
if we do the AND operation between n and n-1, we get 
same bits as in n expect the right most set bit and all the bits to its right.
Example:
(1000) & (0111) = 0000

3. Now If a number is power of 2, then the result of AND operation will be 0.
because in the number power of 2, we have only one set bit.
i.e., n has only one set bit and n-1 has all the set bits to its right.

4. If the AND operation result is 0, then the number is power of 2.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPower2(int n)
{
    if(n==0) return false;
    return (n&(n-1))==0;
}

int main()
{
    int n;
    cin>>n;

    cout<<isPower2(n);

    return 0;
}