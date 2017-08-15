// Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// 
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
// 
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//

// Use stack to record the indexes of the characters '('

int  longestValidParentheses(string s)
{
    stack<int> S1;
    int last = -1;
    int maxsofar = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            S1.push(i);
        }
        else // if (s[i] == ')')
        {
            if (S1.empty())
            {
                last = i;
            }
            else
            {
                S1.pop();
                if (S1.empty())
                {
                    maxsofar = std::max(maxsofar, i-last);
                }
                else
                {
                    maxsofar = std::max(maxsofar, i-S1.top());
                }
            }
        }
    }
    
    return maxsofar;
}
