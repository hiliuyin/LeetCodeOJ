// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

class Solution {
public:
    vector<int> grayCode(int n) {
        
    if (n <= 0) return{0};
    if (n == 1) return{ 0, 1 };
    if (n == 2) return{ 0, 1, 3, 2 };

    std::vector<int> codes = { 0, 1, 3, 2 };
    for (int i = 2; i < n; ++i)
    {
        int pow = std::pow(2, i);
        int prevIndex = pow;
        int startValue = pow;
        int num = pow / 2;
        for (int j = 1; j <= pow; ++j)
        {
            int code = codes[prevIndex - j];
            codes.emplace_back(code + startValue);
        }
    }
    return codes;

    }
};


class Solution {
public:
    vector<int> grayCode(int n) {
    if (n == 0) return {0};

    std::vector<int> codes = {0, 1};
    for (int bits = 2; bits <= n; ++bits)
    {
        int size = (int)codes.size();
        for (int i = 0; i < size; ++i)
        {
            codes.emplace_back(codes[size-i-1]+size);
        }
    }

    return codes;
}
};
