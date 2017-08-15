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
        int num = 0;
        for (const auto& ch : s) {
            num = num * 26 + (ch - 'A' + 1);
        }
        return num;
    }
};
