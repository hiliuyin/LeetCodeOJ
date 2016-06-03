/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
std::string addBinary(std::string a, std::string b)
{
    if (a.empty()) return b;
    if (b.empty()) return a;

    std::string s(std::max(a.size(), b.size())+1, '0');
    int i = a.size() - 1;
    int j = b.size() - 1;
    int k = s.size() - 1;
    int carry = 0;
    while (k >= 1)
    {
        int digitA = (i >= 0) ? ((a[i] == '1') ? 1 : 0) : 0;
        int digitB = (j >= 0) ? ((b[j] == '1') ? 1 : 0) : 0;
        
        int digit = digitA + digitB + carry;
        carry = digit / 2;
        s[k] = (digit % 2 == 1) ? '1' : '0';

        i--;
        j--;
        k--;
    }

    if (carry != 0)
        s[0] = '1';
    else
        s.erase(s.begin());

    return s;
}
};
