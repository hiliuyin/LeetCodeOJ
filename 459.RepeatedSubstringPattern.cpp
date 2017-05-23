/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

bool repeatedSubstringPattern(string s) {
    if (s.empty()) return false;
    const int sz = s.size();
    
    auto leftShift = [&](const string& str, int shift) {
        string ret = str.substr(shift);
        ret += str.substr(0, shift);
        return ret;
    };
    
    for (int i = 1; i <= sz/2; ++i) {
        if (sz % i == 0) {
            string nextStr = leftShift(s, i);
            if (s == nextStr) return true;
        }
    }
    return false;
}
