/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        std::vector<int> sCount(26), tCount(26);
        for (int i = 0, iEnd = s.size(); i < iEnd; ++i)
        {
            sCount[s[i]-'a']++;
            tCount[t[i]-'a']++;
        }
        
        return sCount == tCount;
    }
};
