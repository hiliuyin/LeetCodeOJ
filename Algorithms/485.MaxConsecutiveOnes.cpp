/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxsofar = 0, maxendinghere = 0;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        maxendinghere = (nums[i] == 1) ? maxendinghere+1 : 0;
        maxsofar = std::max(maxendinghere, maxsofar);
    }
    return maxsofar;
}
