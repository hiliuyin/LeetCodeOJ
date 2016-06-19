/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
    const std::size_t size_;
    vector<int> sums_;

public:
    NumArray(vector<int> &nums) : size_(nums.size()), sums_(size_+1, 0)
    {
        for (int i = 0; i < (int)size_; ++i)
        {
            sums_[i+1] = sums_[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return sums_[j+1] - sums_[i];
    }
};
