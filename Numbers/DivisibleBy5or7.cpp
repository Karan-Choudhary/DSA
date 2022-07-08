/*
Problem - How many numbers between 1 and 1000 are divisible by 5 or 7
*/

#include<bits/stdc++.h>
using namespace std;

int divisibleBy(int n, int a, int b)
{
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    return c1+c2-c3;
}

int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    cout<<divisibleBy(n, a, b)<<endl;
    return 0;
}