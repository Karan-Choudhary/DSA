/*
Problem - Given a nxm matrix.
Write an algorithm to find that the given value exists in the matrix 
or not.
Integers in each row are sorted in ascending order left to right.
Integers in each column are sorted in ascending order from top to bottom.

Complexity of Bruteforce: O(n*m)

Optimized Solution:
1. Start from top right element.
2. You are at (r,c)
if(matrix[r][c] == target)
    return true;
if(matrix[r][c] > target)
    c--;
else 
    r++;

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,target;
    cin>>n>>m>>target;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    // Optimized Search Solution:
    int r=0, c=m-1;
    while(r<n and c>=0)
    {
        if(a[r][c] == target)
        {
            cout<<"Found at ("<<r<<","<<c<<")"<<endl;
        }
        if(a[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    return 0;
}