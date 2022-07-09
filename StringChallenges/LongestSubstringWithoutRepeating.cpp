/*
Problem - Longest substring without repeating characters
Given a string s, find the length of the longest
substring without repeating characters.

Example: 
Input: s="abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Approach: 
1. While iterating mark the position of each character
2. At i'th character, check the previous occurrence nad 
decide the start of the substring accordingly.

Intuitively:
Maintain a previous index array for each character and a start index
which help us to find the max length.
1. Traverse the string from i=0 to n-1;
2.  if the element at the position of current character in previous index array
is greater than the start index, then update the start index.
3. update the previous index of current character.
4. update the max length as max of max length and i-start.
*/


#include<bits/stdc++.h>
using namespace std;

// This approach fails in case abcad
int LongestSubstringWithoutRep(string str)
{
    int n = str.length();
    int cntArr[95]={0};
    int max_len=0;
    int i=0,j=0;
    int count=0;
    while(j<n)
    {
        if(cntArr[str[j]-' ']==0)
        {
            count++;
            cntArr[str[j]-' ']++;
            j++;
        }
        else
        {
            max_len = max(max_len,count);
            count=0;
            while(i!=j)
            {
                cntArr[str[i]-' ']--;
                i++;
            }
        }
    }
    max_len = max(max_len,count);
    return max_len;
}

int LongestSubstringWithoutRepeating(string s)
{
    vector<int> cntArr(256,-1);
    int max_len=0;
    int start=-1;
    for(int i=0;i<s.size();i++)
    {
        if(cntArr[s[i]]>start)
        {
            start = cntArr[s[i]];
        }
        cntArr[s[i]]=i;
        max_len = max(max_len,i-start);
    }
    return max_len;
}

int main()
{
    string str;
    getline(cin,str);

    cout<<LongestSubstringWithoutRepeating(str);

    return 0;
}