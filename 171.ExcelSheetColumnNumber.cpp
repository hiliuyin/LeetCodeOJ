/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

// 26进制数
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (auto it = s.cbegin(); it != s.cend(); ++it)
        {
            result = result*26 + (*it - 'A' + 1);
        }
        return result;
    }
};
