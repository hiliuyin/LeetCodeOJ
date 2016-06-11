/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
*/

bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
    if (nums.size() <= 1) return false;

    std::unordered_map<int, int> m;
    for (int i = 0, iEnd = (int)nums.size(); i < iEnd; ++i)
    {
        auto it = m.find(nums[i]);
        if (it != m.end())
        {
            if ((i - it->second) <= k)
                return true;
            m[nums[i]] = i;
        }
        else
        {
            m.emplace(nums[i], i);
        }
    }
    return false;
}
