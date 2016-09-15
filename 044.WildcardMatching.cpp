/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

// Solution 1: DP
// res[i]表示 s的前i个字符 和 p的前j个字符的匹配结果
// 递推式分两种情况
// 1) p[j]为'*'，只要res[i]中有true，那么res[i+1]...res[sz]则全能匹配上
// 2) p[j]不是'*'，那么res[i+1]的结果要看res[i](上次迭代的结果) 以及 p[j]和s[i]是否可以匹配
bool isMatch(std::string s, std::string p)
{
    if (p.empty())
        return s.empty();
    
    const int sz = (int)s.size();
    bool *res = new bool[sz+1];
    for (int i = 1; i <= sz; ++i)
        res[i] = false;
    res[0] = true; // res[0]需要初始化为true，因为此时相当于两个空字符串匹配
    
    for (int j = 0, jEnd = (int)p.size(); j < jEnd; ++j)
    {
        if (p[j] == '*')
        {
            int i = 0;
            while (i <= sz && !res[i])
                i++;
            for (; i <= sz; ++i)
            {
                res[i] = true;
            }
        }
        else
        {
            for (int i = sz-1; i >= 0; --i)
            {
                res[i+1] = res[i] && (p[j] == '?' || s[i] == p[j]);
            }
        }

        res[0] = res[0] && p[j] == '*';
    }

    return res[sz];
}

// Solution 2: Greedy
