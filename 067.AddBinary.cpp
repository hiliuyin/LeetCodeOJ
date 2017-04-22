/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

std::string addBinary(std::string a, std::string b) {
    if (a.empty()) return b;
    if (b.empty()) return a;

    std::string s;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry == 1)
    {
        int digitA = (i >= 0) ? ((a[i] == '1') ? 1 : 0) : 0;
        int digitB = (j >= 0) ? ((b[j] == '1') ? 1 : 0) : 0;
        
        int sum = digitA + digitB + carry;
        carry = sum/2;
        s = static_cast<char>((sum%2 == 1) ? '1' : '0') + s;

        i--;
        j--;
    }

    return s;
}
