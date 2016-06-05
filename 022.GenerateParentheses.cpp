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

std::vector<std::string> generateParenthesis(int n)
{
    if (n <= 0) return {};

    std::vector<std::string> result;
    std::function<void(std::vector<std::string>&, std::string, int, int)> helper =
    [&](std::vector<std::string> &result, std::string parth, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            result.emplace_back(parth);
            return;
        }
        
        if (left != 0)
            helper(result, parth+"(", left-1, right);
        
        if (left < right)
            helper(result, parth+")", left, right-1);

    };
    
    std::string parth;
    
    helper(result, parth, n, n);
    
    return result;
}

};
