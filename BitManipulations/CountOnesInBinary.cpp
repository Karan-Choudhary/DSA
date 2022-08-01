/*
Count Ones in Binary Representation
Problem - Count the number of ones in binary representation of a number.
Example -
Input - 5
Output - 2

Input - number
Output - number of ones in binary representation of the number

Optimized Approach - 
1. Given a number n, we can find the n-1 number by flipping the right most set bit 
along with all the bits to its right.
Example: n = 19, n-1 = 18
19 = 01011 right most set bit is at the position 3
18 = 01010

2. Now do AND operation between n and n-1.
if we do the AND operation between n and n-1, we get 
same bits as in n expect the right most set bit and all the bits to its right.
Example:
(01011) & (01010) = 01010 
the result has same bits expect the right most set bit.

3. When we do AND operation between n and n-1 we get
same bits as in n expect the right most set bit.
i.e., we can say that we counted the one set bit.

4. now store n-1 in n
5. Repeat the above steps until we get the result of n AND n-1 as 0.
n=19 = (01011)
n-1=18 = (01010)                    set_bit_count=1
n = n & n-1 = 01010 = 18

n = 18 = (01010)
n-1=17 = (01001)                    set_bit_count=2
n = n & n-1 = 01000 = 16

n = 16 = (01000)
n-1=15 = (01111)                      set_bit_count=3
n = n & n-1 = 0000 = 0

i.e., in original number i.e., 19, there are 3 set bits.
*/

#include<bits/stdc++.h>
using namespace std;

int CountSetBits(int n)
{
    int count=0;
    while(n!=0)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    cout<<CountSetBits(n);
    return 0;
}