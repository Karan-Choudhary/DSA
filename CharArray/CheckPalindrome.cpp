/*
Problem = Check palindrome in a char arrary
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char a[n+1];
    cin>>a;

    bool check=true;

    for(int i=0;i<n/2;i++)
    {
        if(a[i]!=a[n-i-1])
        {
            check=false;
            break;
        }
    }

    if(check) cout<<"Palindrome";
    else cout<<"Not Palindrome";
    return 0;
}