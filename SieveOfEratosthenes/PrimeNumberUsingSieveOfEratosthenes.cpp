/*
Problem - Find all the prime numbers in the given range

Example - find all prime numbers between 0 to 50
Output - 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47

Optimized Approach -
1. We can use Sieve of Eratosthenes to find all the prime numbers in the given range.
2. Make an array of 50 elements.
3. Mark all the multiples of the prime numbers.
4. In last those elements which are not marked, they are prime numbers.
*/

#include<bits/stdc++.h>
using namespace std;

void PrimeNumberUsingSieveOfEratosthenes(int a, int n)
{
    bool arr[51] = {0};
    if(a<2) a=2;

    for(int i=2;i<=n;i++)
    {
        if(arr[i] == 0 && i*i<=n)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                arr[j] = 1;
            }
        }
    }
    for(int i=a;i<=n;i++)
    {
        if(arr[i] == 0)
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;

    PrimeNumberUsingSieveOfEratosthenes(a,b);

    return 0;
}