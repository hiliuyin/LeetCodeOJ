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

vector<string> generateParenthesis(int n) {
    std::vector<string> res;
    
    std::function<void(string, int, int)> helper = [&](string str, int l, int r) {
        if (r == 0) {
            res.emplace_back(str);
            return;
        }
        
        if (l > 0) {
            helper(str+"(", l-1, r);
        }
        
        if (l < r) {
            helper(str+")", l, r-1);
        }
    };
    
    std::string str;
    helper(str, n, n);
    
    return res;
}
