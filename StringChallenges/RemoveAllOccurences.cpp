#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
        int i=0;
        int p=0;
        
        int pSize = part.length();
        while(i<s.length())
        {
            if(p == pSize-1)
            {
                s = s.substr(0,i-pSize+1)+s.substr(i+1,s.length()-i+1);
                i=0;
                p=0;
            }
            else if(s[i] == part[p])
            {
                i++;
                p++;
            }
            else
            {
                i++;
                p=0;
            }
        }
        return s;
    }

int main()
{
    string str="daabcbaabcbc";
    
    cout<<removeOccurrences(str,"abc");
    
    return 0;
}