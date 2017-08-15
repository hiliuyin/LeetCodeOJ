/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

// Solution 1
int missingNumber(vector<int>& nums)
{
    unsigned long long sum = 0;
    for (const auto& num : nums)
        sum += num;
  
    return (nums.size()+1)*nums.size()/2 - sum;
}

// Solution 2: use std::accumulate
int missingNumber(vector<int>& nums) {
    return (nums.size() + 1) * nums.size()/2 - std::accumulate(nums.begin(), nums.end(), 0LL);
}
