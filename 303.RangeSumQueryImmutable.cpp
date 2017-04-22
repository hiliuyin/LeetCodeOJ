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
    vector<int> sum_;

public:
    NumArray(vector<int> nums) : sum_(nums.size()+1, 0) {
        for (int i = 0, iEnd = nums.size(); i < iEnd; ++i)
            sum_[i+1] = sum_[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return sum_[j+1] - sum_[i];
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
