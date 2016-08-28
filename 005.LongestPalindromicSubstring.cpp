/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
int P[1000][1000];

string longestPalindrome(string s)
{
    const int sz = s.size();
    if (sz <= 1) return s;
    
    int low = 0, high = 0;
    for (int i = 0; i < 1000; ++i)
    {
        P[i][i] = true;
    }
    
    for (int i = 0; i < sz-1; ++i)
    {
        if (s[i] == s[i+1])
        {
            P[i][i+1] = true;
            low = i;
            high = i+1;
        }
    }
    
    for (int len = 3; len <= sz; ++len)
    {
        for (int i = 1, iEnd = sz-len+2; i < iEnd; ++i)
        {
            if (P[i][i+len-3] == true && s[i-1] == s[i+len-2])
            {
                P[i-1][i+len-2] = true;
                low = i-1;
                high = i+len-2;
            }
        }
    }
    return s.substr(low, high-low+1);
}

};
