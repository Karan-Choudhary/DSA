/*
Problem - Form the biggest number from the given numeric string.
Example :-
Input :- "1234"
Output :- "4321"
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    sort(str.begin(), str.end(), greater<char>());
    cout<<str<<endl;
}