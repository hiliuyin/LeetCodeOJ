/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

// solution 1: use std::string
bool isValid(std::string s) {
    if (s.empty()) return false;
    
    std::string brackets;
    for (int i = 0; i < s.size(); ++i) {
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

// solution 2: use std::stack
bool isValid(std::string s) {
    if (s.empty()) return false;
    
    std::stack<char> paren;
    for (const auto& ch : s) {
        if (!paren.empty()) {
            auto x = paren.top();
            if ((ch == '}' && x == '{')
            || (ch == ']' && x == '[')
            || (ch == ')' && x == '(')) {
                paren.pop();
                continue;
            }
        }
        paren.push(ch);
    }
    return paren.empty();
}
