/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/

// Solution 1: traverse twice
int firstUniqChar(std::string s) {
    std::vector<int> vec(26);
    for (int i = 0, iEnd = s.size(); i < iEnd; ++i) {
        ++vec[s[i]-'a'];
    }
    
    for (int i = 0, iEnd = s.size(); i < iEnd; ++i) {
        if (vec[s[i]-'a'] == 1) {
            return i;
        }
    }
    return -1;
}

// Solution 2: hash table
int firstUniqChar(std::string s)
{
    std::unordered_map<char, int> M;
    
    for (int i = 0, iEnd = (int)s.size(); i < iEnd; ++i) {
        auto it = M.find(s[i]);
        if (it != M.end())
            it->second = -1;
        else
            M[s[i]] = i;
    }
    
    int index = -1;
    for (const auto& it : M) {
        if (it.second != -1) {
            if (index == -1)
                index = it.second;
            else if (it.second < index)
                index = it.second;
        }
    }
    return index;
}

// Solution 3: hash table
int firstUniqChar(std::string s) {
    std::unordered_map<char, std::pair<int, int>> m;
    for (int i = 0, iEnd = s.size(); i < iEnd; ++i) {
        m[s[i]].first++;
        m[s[i]].second = i;
    }
    
    int index = s.size();
    for (const auto& p : m) {
        if (p.second.first == 1) index = std::min(index, p.second.second);
    }
    return index == s.size() ? -1 : index;
}
