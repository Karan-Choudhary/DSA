/*
Problem - Make the bit 0 at the given position in the given number.

Example-
Input :-
number = 5
position = 2
Output :-
1

Explanation:
5 = 0101
Number: 0101
Position: 3210
So if we set 0 at second position we get 1.

Approach:
Form a number with all bits set to 0 except the bit at the given position.
We can use left shift operator
Take one's complement of the formed number.
Do bitwise AND operation with the given number and the formed number.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number, position;
    cin>>number>>position;
    int formedNumber = 1<<position;
    formedNumber = ~formedNumber;
    cout<<(number & formedNumber) <<endl;
    return 0;
}