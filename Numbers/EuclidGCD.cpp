/*
Problem - Find the GCD of two numbers using Euclid's algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    int x, y;
    if(a<b)
    {x=a;
    y=b;}
    else
    {
        x=b;
        y=a;
    }
    int rem = 0;
    while(y%x!=0)
    {
        rem = y%x;
        x = rem;
    }
    return rem;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout<<GCD(a,b);
    return 0;
}