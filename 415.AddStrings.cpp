/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

string addStrings(string num1, string num2) {
    if (num1.empty() && num2.empty()) return {};
    if (num1.empty()) return num2;
    if (num2.empty()) return num1;
    
    std::string res;
    int carry = 0;
    int k1 = num1.size() - 1;
    int k2 = num2.size() - 1;
    while (k1 >= 0 && k2 >= 0) {
        int sum = num1[k1] - '0' + num2[k2] - '0' + carry;
        carry = sum/10;
        sum %= 10;
        res = std::to_string(sum) + res;
        --k1;
        --k2;
    }
    
    while (k1 >= 0) {
        int sum = num1[k1] - '0' + carry;
        carry = sum/10;
        sum %= 10;
        res = std::to_string(sum) + res;
        --k1;
    }
    while (k2 >= 0) {
        int sum = num2[k2] - '0' + carry;
        carry = sum/10;
        sum %= 10;
        res = std::to_string(sum) + res;
        --k2;
    }
    if (carry != 0) {
        res = std::to_string(carry) + res;
    }
    return res;
}
