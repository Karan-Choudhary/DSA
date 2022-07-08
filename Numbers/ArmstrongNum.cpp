//  Armstrong Number- a number whose sum of cubes of its digits is equal to the number itself.

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arm=0;
    int temp=n;
    while(n!=0)
    {
        int rem = n%10;
        arm = rem*rem*rem + arm;
        n = n/10;
    }
    if(arm==temp)
    {
        cout<<"Armstrong Number ";
    }
    else
    {
        cout<<"Not Armstrong Number ";
    }
    cout<<arm;
    return 0;
}