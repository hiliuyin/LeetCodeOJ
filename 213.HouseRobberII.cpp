/*
After robbing those houses on that street, the thief has found himself a new place for his thievery 
so that he will not get too much attention. This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/

int rob(std::vector<int>& nums)
{
    if (nums.empty()) return 0;
    
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return std::max(nums[0], nums[1]);
    if (nums.size() == 3) return std::max(std::max(nums[0], nums[1]), nums[2]);
    
    std::vector<int> money(nums);
    money[0] = nums[0];
    money[1] = std::max(nums[0], nums[1]);
    for (int i = 2, iEnd = (int)money.size(); i < iEnd-1; ++i)
    {
        money[i] = std::max(money[i-1], money[i-2]+nums[i]);
    }
    int maxSofar = money[money.size()-2];
    
    money[1] = nums[1];
    money[2] = std::max(nums[1], nums[2]);
    for (int i = 3, iEnd = (int)money.size(); i < iEnd; ++i)
    {
        money[i] = std::max(money[i-1], money[i-2]+nums[i]);
    }
    
    return std::max(maxSofar, money.back());
}
