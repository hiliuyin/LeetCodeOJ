/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

vector<int> findDisappearedNumbers(vector<int>& nums) {
    std::vector<int> result;
    
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        int index = std::abs(nums[i]) - 1;
        nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
    }
    
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        if (nums[i] > 0) result.emplace_back(nums[i]+1);
    }
    
    return result;
}
