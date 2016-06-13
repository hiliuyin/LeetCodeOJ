/*
Given an array of integers, find out whether there are two distinct indices i and j in the array 
such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
    if (nums.size() <= 1 || k <= 0) return false;

    std::multimap<long long, int> m;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i)
    {
        m.emplace(nums[i], i);
    }

    for (auto it1 = m.cbegin(); it1 != m.cend(); ++it1)
    {
        auto it2 = it1;
        while (++it2 != m.cend() && std::abs(it1->first - it2->first) <= t)
        {
            if (std::abs(it1->second - it2->second) <= k)
                return true;
        }
    }
    return false;
}
