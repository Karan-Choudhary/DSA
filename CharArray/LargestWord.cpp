/*
Problem - Given a sentence in which words are separated by spaces,
write an algorithm to find the longest word in the sentence.

For input: use getline() to read the input.
Normally if space encounter then c++ compiler tries to store the 
next word in another variable.
But getline() reads the next word in the same variable.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    char a[n+1];
    cin.getline(a,n+1);
    cin.ignore();

    int max_len=0;
    int curr_len=0;
    int start=0, maxst=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
        {
            max_len = max(max_len,curr_len);
            maxst=start;
            start  = i+1;
            curr_len=0;
        }
        else
        {
            curr_len++;
        }
    }
    if(max_len < curr_len)
    {
        max_len = curr_len;
        maxst=start;
    }
    cout<<max_len<<endl;
    for(int i=0;i<max_len;i++)
    {
        cout<<a[maxst+i];
    }
    return 0;
}