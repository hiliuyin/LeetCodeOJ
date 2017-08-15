/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

// Solution 1: O(nlgn) solution
int findUnsortedSubarray(vector<int>& nums) {
    std::unordered_multimap<int, int> um; // record all the position(index)
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        um.emplace(nums[i], i);
    }
    
    std::sort(nums.begin(), nums.end());
    // from the smallest element
    int res = nums.size();
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        auto range = um.equal_range(nums[i]);
        auto it = range.first;
        for (; it != range.second; ++it) {
            if (it->second == i) {
                res--;
                break;
            }
        }
        if (it == range.second) break;
    }
    if (res == 0) return res;
    // from the largest elem
    for (int i = nums.size()-1; i >= 0; --i) {
        auto range = um.equal_range(nums[i]);
        auto it = range.first;
        for (; it != range.second; ++it) {
            if (it->second == i) {
                res--;
                break;
            }
        }
        if (it == range.second) break;
    }
    return res >= 0 ? res : 0;
}

// Solution 2: O(nlgn)
int findUnsortedSubarray(vector<int>& nums) {
    std::vector<int> temp(nums);
    std::sort(temp.begin(), temp.end());
    
    int low = 0, high = 0;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        if (temp[i] != nums[i]) {
            low = i;
            break;
        }
    }
    
    for (int i = nums.size()-1; i >= 0; --i) {
        if (temp[i] != nums[i]) {
            high = i;
            break;
        }
    }
    return high <= low ? 0 : high - low + 1;
}
