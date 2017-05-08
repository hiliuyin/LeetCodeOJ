/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
*/

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> um;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        auto it = um.find(nums[i]);
        if (it != um.end()) {
            if (i - it->second <= k) return true;
        }
        um[nums[i]] = i;
    }
    return false;
}
