/*
Problem - Minimum Sum Formed By Digits
Given an array of digits (values are from 0 to 9), 
find the minimum possible sum of two numbers formed from digits of the array. 
All digits of given array must be used to form the two numbers.
*/

#include<bits/stdc++.h>
using namespace std;

string MinimumSum(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());

    string first="", second="";

    for(int i=0;i<arr.size();i++)
    {
        if(i%2==0)
        {
            first += (arr[i]+'0');
        }
        else
            second += (arr[i]+'0');
    }

    int first_len = first.length()-1;
    int second_len = second.length()-1;

    int carry = 0;
    string ans = "";
    
    while(first_len >= 0 and second_len >= 0)
    {
        int sum = (first[first_len]-'0')+(second[second_len]-'0')+carry;
        ans += (sum%10+'0');
        carry = sum/10;
        first_len--;
        second_len--;
    }

    while(first_len>=0)
    {
        int sum = (first[first_len]-'0')+carry;
        ans += (sum%10+'0');
        carry = sum/10;
        first_len--;
    }

    while(second_len>=0)
    {
        int sum = (second[second_len]-'0')+carry;
        ans += (sum%10+'0');
        carry = sum/10;
        second_len--;
    }

    if(carry)
        ans += (carry+'0');
    
    while(!ans.empty() and ans.back()=='0')
        ans.pop_back();
        

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<MinimumSum(arr,n);
    
    return 0;
}