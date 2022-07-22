/* Record Breaker:
Problem: 
Isyana is given the number of visitors at her local theme park
on N consecutive days. The number of visitors on the i-th day is Vi.
A day is record breaking if it satisfies both of the following conditions:
1. The number of visitors on the day is strictly larger than the
number of visitors on each of the previous days.
2. Either it is the last day, or the number of visitors on  the day is strictly
larger than the number of visitors on the following day.
Note that the very first day could be a record breaking day.
Please help Isyana to find the number of record breaking days.

Input: 
First line is test cases, T.
Second line is interger N denoting the size of the array.
Third line is N space separated integers denoting the array.

Output: 
For each test case, output one line containing
Case #x: y, where x is the test case number (starting from 1) and
y is the number of record breaking days.
*/

#include<bits/stdc++.h>
using namespace std;

int RecordBreakingDays(int a[], int n)
{
    int mx=-88;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
        {
            if(a[i]>a[i+1])
            {
                ans++;
            }
            mx=a[i];
        }
        else
        {
            if(a[i]>a[i+1] && a[i]>mx)
            {
                ans++;
                mx = max(a[i],mx);
            }
        }
    }
    if(a[n-1]>mx)
    {
        ans++;
    }
    return ans;
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
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    cout<<RecordBreakingDays(a,n);
    return 0;
}