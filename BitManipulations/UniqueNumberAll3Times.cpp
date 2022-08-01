/*
Problem - Find a unique number in an array where all numbers 
expect one, are present thrice.

Example - 
Input - {1,3,2,3,4,2,1,1,3,2}
Output - 4

Optimized Approach - 
1. Make an array assuming the size of int is 64 bits.
2. Now see the binary representation of all elements in the array.
3. In the binary representation of all elements, where-ever the SET BIT
is present, fill the corresponding position in the array with prev_val +1.
4. Those number whose triplets are present, bits of those positions will be the multiple of 3.

{1,3,2,3,4,2,1,1,3,2}

array:

0   1     2
----------------------------------------------------------
3 | 6 | 4 | 0 | 0 | 0 | 0 |       ............. 64 bits
----------------------------------------------------------

5. If we do the modulo operation by 3 on the array, we will get
----------------------------------------------------------
3 | 6 | 4 | 0 | 0 | 0 | 0 |       ............. 64 bits
----------------------------------------------------------
0    0   1
So our unique number will be : 100 which is 4.
*/

#include<bits/stdc++.h>
using namespace std;

bool getBit(int number, int position)
{
    return ((number & (1<< position)) != 0);
}

int setBit(int number, int position)
{
    return (number | (1<<position));
}

int UniqueNumberInTripletsDoubleLoops(int arr[], int n)
{
    // using double loops
    int result=0;
    for(int i=0;i<64;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(getBit(arr[j],i))
            {
                sum++;
            }
        }
        if(sum%3!=0)
        {
            result = setBit(result,i);
        }
    }
    return result;
}

int UniqueNumberInTripletsExtraArray(int arr[], int n)
{
    // using extra array
    int result=0;
    int extra_array[64]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<64;j++)
        {
            if(getBit(arr[i],j))
            {
                extra_array[j]++;
            }
        }
    }
    for(int i=0;i<64;i++)
    {
        if(extra_array[i]%3!=0)
        {
            result = setBit(result,i);
        }
    }
    return result;
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

    cout<<UniqueNumberInTripletsDoubleLoops(arr,n)<<endl;
    cout<<UniqueNumberInTripletsExtraArray(arr,n);

    return 0;
}