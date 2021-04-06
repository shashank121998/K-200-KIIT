#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    string::iterator s1 = str1.begin(), s2 = str2.begin();
    while (s1 != str1.end() || s2 != str2.end())
    {
        if (*s1 != *s2)
        {
            cout << (int)*s1 - (int)*s2;
            break;
        }
        s1++;
        s2++;
    }
}