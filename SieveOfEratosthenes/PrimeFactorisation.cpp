/*
Problem - Find all the prime factors of a given number

Optimized Approach - 
1. Make an array of smallest prime factor.
2. while(n!=1)
{
    print spf[n];
    n = n/spf[n];
}
*/

#include<bits/stdc++.h>
using namespace std;

void SmallestPrimeFactor(int n)
{
    int spf[n+1] = {0};
    for(int i=2;i<=n;i++)
    {
        spf[i]=i;
    }

    for(int i=2;i<=n;i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }

}

int main()
{
    int n;
    cin>>n;

    SmallestPrimeFactor(n);

    return 0;
}