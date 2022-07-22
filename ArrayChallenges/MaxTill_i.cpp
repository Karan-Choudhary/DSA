// Max till i :- Given an array a[] of size n.
// For every i from 0 to n-1 output max(a[0],a[1],...,a[i])

#include<iostream>
using namespace std;

void maxTilli(int arr[], int n)
{
    int max = arr[0];
    cout<<max<<" ";
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max) max = arr[i];
        cout<<max<<" ";
    }
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

    maxTilli(a,n);
    return 0;

}