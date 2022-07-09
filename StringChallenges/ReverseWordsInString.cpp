/*
Problem - Given a character array s, reverse the order of the words.
A word is defined as a sequence of non-space characters.
The words in s will be separated by a single space.
Your code must solve the problem in-place, i.e. without allocating extra space.

Example:
Input:
s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output:
["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
*/

#include<bits/stdc++.h>
using namespace std;

void ReverseWordsInString(vector<char> &s)
{
    // we need to reverse the words position in string
    reverse(s.begin(),s.end());
    int i=0;
    int j=0;
    int s_size = s.size();
    while(i<s_size)
    {
        if(s[i]==' ')
        {
            int start = j;
            int end = i-1;
            while(start<end)
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            cout<<endl;
            i++;
            j=i;
        }
        else
        {
            i++;
        }
    }
    int start = j;
    int end = i-1;
    while(start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    ReverseWordsInString(s);
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
    }
    return 0;
}