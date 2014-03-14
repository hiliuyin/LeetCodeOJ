// Longest Palindromic Substring
// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
//

// Dynamic Programming
// Let P[i][j] to indicate whether or not s[i....j] is a palindromic substring.
// P[i][j] = P[i-1][j-1] if s[i]==s[j]
//         = false       if s[i]!=s[j]

int P[1000][1000];
string longestPalindrome(string s)
{
    if (s.size() <= 1) return s;

    int leftIndex = 0;
    int rightIndex = 0;
    int maxlen = 1;
    
    int ssize = (int)s.size();
    const char* ps = s.data();
    
    for (int i = 0; i < ssize; ++i)
        P[i][i] = 1;
    
    for (int i = 0; i < ssize-1; ++i)
    {
        if (ps[i] == ps[i+1])
        {
            P[i][i+1] = 1;
            if (maxlen < 2)
            {
                maxlen = 2;
                leftIndex = i;
                rightIndex = i+1;
            }
        }
    }
    
    for (int len = 3; len <= ssize; ++len)
    {
        for (int i = 0; i < ssize-len+1; ++i)
        {
            if (ps[i] == ps[i+len-1])
            {
                P[i][i+len-1] = P[i+1][i+len-2];
                if (P[i][i+len-1] == 1 && maxlen < len)
                {
                    maxlen = len;
                    leftIndex = i;
                    rightIndex = i+len-1;
                }
            }
        }
    }

    return string(s, leftIndex, maxlen);
}

