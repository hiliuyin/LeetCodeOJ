/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

// Solution 1: O(n)
int thirdMax(vector<int>& nums) {
    if (nums.size() == 1) return nums.back();
    if (nums.size() == 2) return std::max(nums[0], nums[1]);
    
    long firstMax = (long)INT_MIN-1, secondMax = (long)INT_MIN-1, thirdMax = (long)INT_MIN-1;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        if (nums[i] == firstMax || nums[i] == secondMax || nums[i] == thirdMax)
            continue;
        if (nums[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        }
        else if (nums[i] > secondMax) {
            thirdMax = secondMax;
            secondMax = nums[i];
        }
        else if (nums[i] > thirdMax) {
            thirdMax = nums[i];
        }
    }
    return thirdMax != (long)INT_MIN-1 ? thirdMax : firstMax;
}
