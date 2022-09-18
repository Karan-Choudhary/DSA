/* A password detection system for HackerRank accounts detects a password as similar if the number of vowels is equal to the number of consonants in the password.
Passwords consist of lowercase English characters only, and vowels are a,e,i,o,u.
To check the strength of a password and how easily it can be hacked. some manipulations can be made to the password. 
In one operation, any character of the string can either be incremented or decremented. 
For example: 'f' can be incremented to 'g' or decremented to 'e' .
Note that character 'a' cannot be decremented and 'z' cannot be incremented.
Find the minimum number of operations in which the password can be made similar.

Example:
Input: hack
output: 1
Explanation: 'h' incremented by 1 and it becomes 'i' which is a vowel.
now iack has equal number of vowels and consonants.

Input: abcd
output: 1

input: bigbangt
output: 2
*/
#include <bits/stdc++.h>
using namespace std;

int countMinimumOperations(int s_size, vector<char> &vowels, vector<char> &consonants)
{
    int half = s_size/2;

    int vowel_size = vowels.size();

    vector<int> One;

    for(auto ch : consonants)
    {
        char ch_minus = ch;
        char ch_plus = ch;
        int minusCount = 0;
        int plusCount = 0;

        while( ch_minus != 'a' and ch_minus!= 'e' and ch_minus!= 'i' and ch_minus!= 'o' and ch_minus!= 'u')
        {
            ch_minus--;
            minusCount++;
        }

        while( ch_plus != 'a' and ch_plus!= 'e' and ch_plus!= 'i' and ch_plus!= 'o' and ch_plus!= 'u')
        {
            ch_plus++;
            plusCount++;
        }

        One.push_back(min(plusCount, minusCount));
    }

    // sort both vectors
    sort(One.begin(), One.end());

    int ans = 0;
    for(int i = 0; i < half-vowel_size; i++)
    {
        ans += One[i];
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    // separate vowels and consonants from s and store in maps
    vector<char> vowels;
    vector<char> consonants;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vowels.push_back(s[i]);
        }
        else
        {
            consonants.push_back(s[i]);
        }
    }

    cout<<countMinimumOperations(s.size(), vowels, consonants);

    return 0;
}