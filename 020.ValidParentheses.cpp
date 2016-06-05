/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
bool isValid(std::string s)
{
    if (s.empty()) return false;
    
    std::string brackets;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ')' && brackets.back() == '(')
            brackets.pop_back();
        else if (s[i] == ']' && brackets.back() == '[')
            brackets.pop_back();
        else if (s[i] == '}' && brackets.back() == '{')
            brackets.pop_back();
        else
            brackets.push_back(s[i]);
    }
    
    return brackets.empty();
}
};
