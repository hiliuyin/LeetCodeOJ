// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

// Solution 1:
vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (auto ri = digits.rbegin(); ri != digits.rend(); ++ri) {
        int digit = *ri + carry;
        *ri = digit%10;
        carry = digit/10;
    }
    if (carry != 0) digits.insert(digits.begin(), carry);
    return digits;
}

// Solution 2: Very simple
vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size()-1; i >= 0; --i) {
        if (digits[i] == 9) {
            digits[i] = 0;
        }
        else {
            digits[i]++;
            return digits;
        }
    }
    digits[0] = 1;
    digits.emplace_back(0);
    return digits;
}
