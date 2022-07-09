/*
Problem - From the given string find the character which occurs maximum number of times.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    int count[26] = {0};

    for(int i=0; i<str.size();i++)
    {
        count[str[i]-'a']++;
    }

    int maxCount = INT_MIN;
    int index = -1;

    for(int i=0; i<26; i++)
    {
        if(count[i] > maxCount)
        {
            maxCount = count[i];
            index = i;
        }
    }
    cout<<"Count: "<<maxCount<<endl;
    cout<<"Index: "<<index<<endl;
    cout<<"Character: "<<(char)(index+'a')<<endl;

    return 0;
}