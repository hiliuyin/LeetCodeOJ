/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

void moveZeroes(std::vector<int>& nums)
{
    int index = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        if (*it != 0)
        {
            std::swap(*it, nums[index++]);
        }
    }
}

void moveZeroes(std::vector<int>& nums) {
    std::size_t pos = 0;
    for (std::size_t i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        if (nums[i] != 0)
            std::swap(nums[pos++], nums[i]);
    }
}
