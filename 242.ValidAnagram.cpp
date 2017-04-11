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

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
        
    std::vector<int> sVec(26), tVec(26);
    for (int i = 0, iEnd = s.size(); i < iEnd; ++i) {
        ++sVec[s[i]-'a'];
        ++tVec[t[i]-'a'];
    }

    return sVec == tVec;
}
