/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

// Solution 1
std::vector<int> countBits(int num) {
    std::vector<int> bits{0};
    bits.reserve(static_cast<size_t>(num) + 1);
    for (int i = 1, j = 0; i <= num; ++i, ++j) {
        if ((i & (i-1)) == 0) j = 0;
        bits.emplace_back(bits[j]+1);
    }
    return bits;
}

// Solution 2
std::vector<int> countBits(int num)
{
    std::vector<int> result{0};
    for (int i = 1; i <= num; ++i) {
        result.emplace_back(result[(i-1)&i]+1);
    }
    return result;
}

// Solution 3
std::vector<int> countBits(int num) {
    std::vector<int> bits;
    bits.reserve(static_cast<size_t>(num)+1);
    for (int i = 0; i <= num; ++i) {
        bits.emplace_back(__builtin_popcount(i));
    }
    return bits;
}
