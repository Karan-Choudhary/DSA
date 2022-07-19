/*
Problem - For a given array and an integer K, 
check if any subarray of size K exits in the array 
such that elements in the subarray form a number 
divisible by 3.

Approach:
1. Sum of initial K elements from the array.
2. Use sliding window technique and one by one, start
subtracting elements from the end and adding from the
end.
3. At each step, check if sum divisible by 3 or not. If it is
print the elements.
*/

#include<bits/stdc++.h>
using namespace std;

void DivisibleBy3(vector<int> arr, int n, int k)
{
    pair<int, int> ans;
    int sum=0;

    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }

    bool found=false;
    if(sum%3==0)
    {
        found=true;
        ans = make_pair(0, k-1);
    }

    for(int i=k;i<n;i++)
    {
        if(found) break;
        sum = sum-arr[i-k]+arr[i];
        if(sum%3==0)
        {
            ans = make_pair(i-k+1, i);
            found=true;
        }
    }
    if(!found){
        ans = make_pair(-1,0);
    }
    if(ans.first == -1)
    {
        cout<<"No subarray found"<<endl;
    }
    else
    {
        cout<<"Subarray found"<<endl;
        for(int i=ans.first;i<=ans.second;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    DivisibleBy3(arr,n,k);

    return 0;
}