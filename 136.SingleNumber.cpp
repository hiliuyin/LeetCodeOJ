// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        // for (auto&& num : nums) // in C++11
        for (vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it)
        {
            value ^= *it;
        }
        return value;
    }
};
