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

bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<char, int> m;
    for (const auto& ch : magazine) {
        ++m[ch];
    }    
    for (const auto& ch : ransomNote) {
        if (m.find(ch) == m.end() || m[ch] <= 0) return false;
        else --m[ch];
    }
    return true;
}
