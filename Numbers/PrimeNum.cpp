// Check whether the number is prime or not

#include<iostream>
#include<math.h>    
using namespace std;

int main()
{
    int n;
    cin>>n;

    bool flag=true;

    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cout<<"Non-prime";
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        cout<<"Prime";
    }
    return 0;
}