#include<string>
#include<iostream>
using namespace std;

int binaryToDecimal(int n)
{
    int ans=0;
    int x=1;
    while(n!=0)
    {
        int rem = n%10; 
        ans += rem*x;
        x = x*2;
        n = n/10;
    }
    return ans;
}

int octalToDecimal(int n)
{
    int ans=0;
    int x=1;
    while(n!=0)
    {
        int rem = n%10;
        ans += rem*x;
        x = x*8;
        n = n/10;
    }
    return ans;
}

int hexaDecimalToDecimal(string n)
{
    int ans=0;
    int x = 1;
    int s = n.size();
    for(int i=s-1;i>=0;i--)
    {
        if(n[i] >= '0' && n[i] <= '9')
        {
            ans += x*(n[i]-'0');
        }
        else if(n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x*(n[i]-'A'+10); 
        }
        x *= 16;
    }
    return ans;
}

int decimalToBinary(int n)
{
    int ans=0;
    int x=1;
    while(x<=n)
    {
        x*=2;
    }
    x/=2;
    while(x>0)
    {
        int rem = n/x;
        n  -= rem*x;
        x/=2;
        ans = ans*10 + rem;
    }
    return ans;
}

int decimalToOctal(int n)
{
    int ans=0;
    int x=1;
    while(x<=n)
    {
        x*=8;
    }
    x/=8;
    while(x>0)
    {
        int rem = n/x;
        n  -= rem*x;
        x/=8;
        ans = ans*10 + rem;
    }
    return ans;
}

string decimalToHexaDecimal(int n)
{
    int x=1;
    string ans="";
    while(x<=n)
    {
        x*=16;
    }
    x/=16;
    while(x>0)
    {
        int rem = n/x;
        n -= rem*x;
        x/=16;

        if(rem <= 9)
        {
            ans = ans + to_string(rem);
        }
        else
        {
            ans.push_back(rem+'A'-10);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
     
    //  cout<<binaryToDecimal(n)<<endl;
    // cout<<octalToDecimal(n)<<endl;
    // cout<<hexaDecimalToDecimal(n)<<endl;
    // cout<<decimalToBinary(n)<<endl;
    // cout<<decimalToOctal(n)<<endl;
    cout<<decimalToHexaDecimal(n)<<endl;
    return 0;
}