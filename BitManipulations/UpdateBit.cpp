/*
Problem - Update the bit at the given position in the given number.

Example :-
Input :-
number = 5
position = 1
Update by = 1
Output :-
7

Explanation:
5 = 0101
Number: 0101
Position: 3210
So if we set 1 at position 1 we get 111 in binary and 7 in decimal.

Approach:
First clear the bit at the given position.
Then set the bit at the given position.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number, position, updateBy;
    cin>>number>>position>>updateBy;
    int formedNumber = 1<<position;
    formedNumber = ~formedNumber;
    number = (number & formedNumber);

    formedNumber = updateBy<<position;
    number = (number | formedNumber);
    cout<<number<<endl;

    return 0;
}