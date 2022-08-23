// we have some amount of money and each chocolate price is 1 Rupee
// Also we can but 1 chocolate with 3 chocolate wrappers
// Find how many chocolates we can buy with this money

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num_chocolates=n;
    int rem;
    while(n>2)
    {
        int newCho = n/3;
        num_chocolates += newCho;
        rem = n-(newCho*3);
        n = newCho+rem;
        if(rem<0)
        {
            break;
        }
    }
    cout<<num_chocolates;
    return 0;
}