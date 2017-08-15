/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

// Solution 1: binary search, O(nlogn)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    auto binarySearch = [&nums](int low, int high, int target) -> int {
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        };
        return -1;
    };

    for (int i = 0, iEnd = nums.size()-1; i < iEnd; ++i) {
        int index = binarySearch(i+1, iEnd, target-nums[i]);
        if (index > i)
            return {i+1, index+1};
    }
    return {-1, -1};
}

// Solution2: O(n)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (nums[low] + nums[high] != target) {
        if (nums[low] + nums[high] > target) high--;
        else low++;
    }
    return {low+1, high+1};
}
