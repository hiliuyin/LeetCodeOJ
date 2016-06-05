/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
void generateHelper(std::vector<std::string> &result, std::string parth, int left, int right)
{
    if (left == 0 && right == 0)
    {
        result.emplace_back(parth);
        return;
    }
    
    if (left != 0)
        generateHelper(result, parth+"(", left-1, right);
    
    if (left < right)
        generateHelper(result, parth+")", left, right-1);
}

std::vector<std::string> generateParenthesis(int n)
{
    if (n <= 0) return {};

    std::vector<std::string> result;
    std::string parth;
    
    generateHelper(result, parth, n, n);
    
    return result;
}
};
