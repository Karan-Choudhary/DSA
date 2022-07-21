/*
Problem - Combination Sum
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

#include<bits/stdc++.h>
using namespace std;

void CombinationSum(int index, vector<int> &candidates, vector<int> temp, int target, vector<vector<int>> &ans)
{
    // base cases - 1
    if(target == 0)
    {
        ans.push_back(temp);
        return;
    }

    // base cases - 2
    if(target < 0)
        return;
    
    // base cases - 3
    if(index >= candidates.size())
        return;

    // Not including element at index
    CombinationSum(index+1, candidates, temp, target, ans);

    // Including element at index
    temp.push_back(candidates[index]);
    CombinationSum(index, candidates, temp, target - candidates[index], ans);
    
    // backtracking 
    temp.pop_back();
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> candidates;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        candidates.push_back(x);
    }

    vector<vector<int>> ans;
    vector<int> temp;

    CombinationSum(0, candidates, temp, target, ans);

    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}