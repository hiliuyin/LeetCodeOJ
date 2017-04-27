/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// Solution 1: O(n^2)
vector<int> findAnagrams(string s, string p) {
    std::vector<int> m(26, 0);
    for (const auto& ch : p) {
        m[ch - 'a']++;
    }
        
    std::vector<int> result;
    for (int i = 0, iEnd = s.size() - p.size() + 1; i < iEnd; ++i) {
        if (!result.empty() && result.back() == i-1 && s[i-1] == s[i+p.size()-1]) {
            result.emplace_back(i);
            continue;
        }
        std::vector<int> mCopy(m);
        bool found = true;
        for (int k = 0, kEnd = p.size(); k < kEnd; ++k) {
            if (mCopy[s[i+k] - 'a'] == 0) {
                found = false;
                break;
            }
            mCopy[s[i+k] - 'a']--;
        }
        if (found) result.emplace_back(i);
    }
    return result;
}
