/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that
adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

int rob(std::vector<int>& nums)
{
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return std::max(nums[0], nums[1]);
    
    std::vector<int> money(nums.size());
    money[0] = nums[0];
    money[1] = std::max(nums[0], nums[1]);
    for (int i = 2, iEnd = (int)money.size(); i < iEnd; ++i)
    {
        money[i] = std::max(money[i-2]+nums[i], money[i-1]);
    }
    
    return money.back();
}
