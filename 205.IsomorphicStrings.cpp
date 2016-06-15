/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

bool isIsomorphic(std::string s, std::string t)
{
    std::map<char, char> m1, m2;
    for (int i = 0, iEnd = (int)s.size(); i < iEnd; ++i)
    {
        if (m1.find(s[i]) != m1.end())
        {
            if(m1[s[i]] != t[i])
                return false;
        }
        else
        {
            m1.emplace(std::make_pair(s[i], t[i]));
        }
        
        if (m2.find(t[i]) != m2.end())
        {
            if(m2[t[i]] != s[i])
                return false;
        }
        else
        {
            m2.emplace(std::make_pair(t[i], s[i]));
        }
    }
    
    return true;
}
