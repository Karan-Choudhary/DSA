/*

AAA
BBB
CCC

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char val = 'A'+i-1;
        for(int j=1;j<=n;j++)
        {
            cout<<val;
        }
        cout<<endl;
    }
}