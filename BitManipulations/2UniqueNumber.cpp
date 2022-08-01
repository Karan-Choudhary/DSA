/*
Problem - Find the 2 unique numbers in an array where all numbers 
expect two, are present twice.

Example - 
Input - {2,4,6,7,4,5,6,2}
Output - 5,7 OR 7,5

Optimized Approach -
1. We can use XOR operation to find the unique number.
2. Find the XOR_SUM of all the numbers in the array.
3. Find the set bit in the XOR_SUM.
according to example 
at the end we will have XOR of 5 and 7 which is 0010
7 - 0111
5- 0101
^-  0010
Now, we know that if the in the XOR_SUM we have set bit at 1st position,
then one of the number have set bit at 1st position.
4. Now, do XOR between all the numbers in the array
where the position of right most set bit in XOR_SUM is same as the position of right most set bit in the number.
5. We will get out first unique number.
6. Now, do XOR between XOR_SUM and first unique number.
7. We will get out second unique number.
*/

#include<bits/stdc++.h>
using namespace std;

bool getBit(int number, int position)
{
    return ((number & (1 << position)) != 0);
}

void TwoUniqueNumber(int arr[], int n)
{
    int xor_sum = 0;
    for(int i=0;i<n;i++)
    {
        xor_sum ^= arr[i];
    }

    int set_bit_pos = 0;
    int set_bit=0;
    int temp = xor_sum;
    while(set_bit!=1)
    {
        set_bit = xor_sum & 1;
        set_bit_pos++;
        xor_sum = xor_sum >> 1;
    }

    int first_number = 0;
    for(int i=0;i<n;i++)
    {
        if(getBit(arr[i],set_bit_pos-1))
        {
            first_number ^= arr[i];
        }
    }
    cout<<first_number<<","<<(temp ^ first_number);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    TwoUniqueNumber(arr,n);

    return 0;
}