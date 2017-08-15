// Interleaving String 
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
// 
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
// 
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.
//

// Dynamic Programming
// S[i][j] is whether s1[1...i] and s2[1....j] could formed the interleaving string s3[1...(i+j+1)].
// S[i][j] = S[i-1][j-1]  s1[i]==s2[j] && s1[i]==s3[i+j+1] && s1[i]==s3[i+j]
//         = S[i-1][j]    s1[i]==s3[i+j+1]
//         = S[i][j-1]    s2[j]==s3[i+j+1]
//         = false        otherwise
//

// Use the Memorization method to solve the problem from up to bottom recursively
bool isInterleaveHelper(vector<vector<int>> &S,
                        string s1, int m,
                        string s2, int n,
                        string s3)
{
    if (S[m][n] != -1)
        return S[m][n];
    
    if (m == 1 && n == 0 && s1[0] == s3[0])
    {
        S[1][0] = 1;
        return 1;
    }
    if (m == 0 && n == 1 && s2[0] == s3[0])
    {
        S[0][1] = 1;
        return 1;
    }
    
    if (m != 0 && n != 0 && s1[m-1] == s2[n-1])
    {
        if (s3[m+n-1] == s1[m-1])
            S[m][n] = isInterleaveHelper(S, s1, m-1, s2, n, s3)
                   || isInterleaveHelper(S, s1, m, s2, n-1, s3);
        else
            S[m][n] = 0;

        return S[m][n];
    }
    else if (m != 0 && s3[m+n-1] == s1[m-1])
    {
        S[m][n] = isInterleaveHelper(S, s1, m-1, s2, n, s3);
        return S[m][n];
    }
    else if (n != 0 && s3[m+n-1] == s2[n-1])
    {
        S[m][n] = isInterleaveHelper(S, s1, m, s2, n-1, s3);
        return S[m][n];
    }
    else
    {
        S[m][n] = 0;
        return 0;
    }
}

bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size()) return false;
    if (s3.size() == 0) return true;

    vector<vector<int>> S(s1.size()+1);
    for (int i = 0; i <= s1.size(); ++i)
    {
        for (int j = 0; j <= s2.size(); ++j)
        {
            S[i].push_back(-1);
        }
    }

    return isInterleaveHelper(S, s1, (int)s1.size(), s2, (int)s2.size(), s3);
}

// Use the bottom-up method
bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size()) return false;
    
    if (s3.size() == 0) return true;
    
    bool S[s1.size()+1][s2.size()+1];
    memset(S, 0, sizeof(S));

    int i, j;
    for (i = 0; i < s1.size(); ++i)
    {
        if (s1[i] == s3[i])
            S[i+1][0] = true;
        else
            break;
    }
    
    for (j = 0; j < s2.size(); ++j)
    {
        if (s2[j] == s3[j])
            S[0][j+1] = true;
        else
            break;
    }
    
    for (i = 0; i < s1.size(); ++i)
    {
        for (j = 0; j < s2.size(); ++j)
        {
            if (s1[i] == s2[j] && s1[i] == s3[i+j+1])
                S[i+1][j+1] = S[i][j+1] || S[i+1][j];
            else if (s1[i] == s3[i+j+1])
                S[i+1][j+1] = S[i][j+1];
            else if (s2[j] == s3[i+j+1])
                S[i+1][j+1] = S[i+1][j];
        }
    }

    return S[s1.size()][s2.size()];
}
