/* Spiral Order Matrix Traversal - 
Input:  
1    2   3   4
5    6   7   8
9   10  11  12
13  14  15  16
Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

Approach :
Size of matrix = n*m
1. take 4 variables 
row_start = 0
row_end = n-1
col_start = 0
col_end = m-1

2. Traverse in row_start row from left to right and inc row_start by 1.
3. Traverse in col_end column from top to bottom and dec col_end by 1.
4. Traverse in row_end row from right to left and dec row_end by 1.
5. Traverse in col_start column from bottom to top and inc col_start by 1.
Repeat step 2 to 5 until row_start > row_end and col_start > col_end.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    int row_start =0;
    int row_end = n-1;
    int col_start = 0;
    int col_end = m-1;
    int total = m*n;
    int count=0;

    while(row_start <= row_end && col_start <= col_end)
    {
        // for row_start
        for(int i=col_start; count<total && i<=col_end; i++)
        {
            cout<<a[row_start][i]<<" ";
            count++;
        }
        row_start++;

        // for col_end
        for(int i=row_start; count<total && i<=row_end; i++)
        {
            cout<<a[i][col_end]<<" ";
            count++;
        }
        col_end--;

        // for row_end
        for(int i=col_end; count<total &&  i>=col_start; i--)
        {
            cout<<a[row_end][i]<<" ";
            count++;
        }
        row_end--;

        // for col_start
        for(int i=row_end; count<total && i>=row_start; i--)
        {
            cout<<a[i][col_start]<<" ";
            count++;
        }
        col_start++;
    }
    return 0;
}