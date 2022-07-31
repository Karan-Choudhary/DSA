/*
Problem - Set the bit at the given position in the given number. i.e. need to set 1 
Example :-
Input :-
number = 5
position = 1
Output :-
7

Explanation:
5 = 0101
Number: 0101
Position: 3210
So if we set 1 at position 1 we get 111 in binary and 7 in decimal.

Approach:
Form a number with all bits set to 0 except the bit at the given position.
We can use left shift operator
Do bitwise OR operation with the given number and the formed number.
if number | formed number is non-zero, then the bit is 1.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number, position;
    cin>>number>>position;
    int formedNumber  = 1<<position;
    cout<<(number | formedNumber)<<endl;
    return 0;
}