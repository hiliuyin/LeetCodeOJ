/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/

int firstUniqChar(std::string s)
{
    std::unordered_map<char, int> M;
    
    for (int i = 0, iEnd = (int)s.size(); i < iEnd; ++i)
    {
        auto it = M.find(s[i]);
        if (it != M.end())
            it->second = -1;
        else
            M[s[i]] = i;
    }
    
    int index = -1;
    for (const auto& it : M)
    {
        if (it.second != -1)
        {
            if (index == -1)
                index = it.second;
            else if (it.second < index)
                index = it.second;
        }
    }
    return index;
}
