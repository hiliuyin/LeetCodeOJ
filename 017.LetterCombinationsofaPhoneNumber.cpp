/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
void helper(std::vector<std::string> &result, std::string s, std::string digits,
            std::unordered_map<char, std::string> &digitsToLetters)
{
    if (digits.empty())
    {
        result.emplace_back(s);
        return;
    }

    for (auto&& letter : digitsToLetters[digits[0]])
    {
        helper(result, s+letter, digits.substr(1), digitsToLetters);
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    if (digits.empty()) return {};

    std::unordered_map<char, std::string> digitsToLetters =
    {
        {'0', ""}, {'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    
    std::vector<std::string> result;
    std::string s;
    helper(result, s, digits, digitsToLetters);
    
    return result;
}
