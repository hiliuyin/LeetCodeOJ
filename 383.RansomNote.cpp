/*
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

bool canConstruct(string ransomNote, string magazine)
{
    std::unordered_map<char, int> M;
    for (int i = 0, iEnd = (int)magazine.size(); i < iEnd; ++i)
    {
        if (M.find(magazine[i]) == M.end())
            M[magazine[i]] = 1;
        else
            M[magazine[i]]++;
    }
    
    for (int i = 0, iEnd = (int)ransomNote.size(); i < iEnd; ++i)
    {
        auto it = M.find(ransomNote[i]);
        if (it == M.end())
            return false;
        if (it->second == 0)
            return false;
        it->second--;
    }
    
    return true;
}

