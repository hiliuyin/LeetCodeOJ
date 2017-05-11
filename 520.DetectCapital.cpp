/*
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
  All letters in this word are capitals, like "USA".
  All letters in this word are not capitals, like "leetcode".
  Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

// traverse the word in reversed order
bool detectCapitalUse(string word) {
    if (word.size() <= 1) return true;

    for (int i = word.size()-1; i > 1; --i) {
        if (isupper(word[i]) != isupper(word[i-1])) {
            return false;
        }
    }
    if (islower(word[0]) && isupper(word[1])) return false;
    return true;
}

// Solution 2:
bool detectCapitalUse(string word) {
    int upperNum = 0;
    for (const auto& ch : word) {
        if (std::isupper(ch)) upperNum++;
    }
    if (upperNum == 1) return std::isupper(word[0]);
    return upperNum == 0 || upperNum == word.size();
}

