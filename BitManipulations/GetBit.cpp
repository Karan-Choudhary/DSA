/*
Problem - Find the bit at the given position in the given number.


Example :-
Input :-
number = 5
position = 2
Output :-
1

Explanation:
5 = 0101
Number: 0101
Position: 3210

So at second position of the number, we have 1.


Approach:
Form a number with all bits set to 0 except the bit at the given position.
We can use left shift operator
Do bitwise AND operation with the given number and the formed number.
if number & formed number is non-zero, then the bit is 1.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number, position;
    cin>>number>>position;
    int formedNumber = 1<<position;
    if((number & formedNumber)!=0 )
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }

    return 0;
}