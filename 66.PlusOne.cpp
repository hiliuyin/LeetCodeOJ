// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (vector<int>::reverse_iterator ri = digits.rbegin(); ri != digits.rend(); ++ri)
        {
            int digit = *ri + carry;
            *ri = digit%10;
            carry = digit/10;
        }
        if (carry != 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};
