/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

vector<int> findDuplicates(vector<int>& nums) {
    std::vector<int> result;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        int index = std::abs(nums[i]) - 1;
        if (nums[index] > 0)
            nums[index] = -nums[index];
        else
            result.emplace_back(index+1);
    }
    return result;
}
