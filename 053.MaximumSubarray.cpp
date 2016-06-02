// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxendinghere = nums[0], maxsofar = nums[0]; // because nums containing at least one number
        for (vector<int>::const_iterator it = nums.cbegin()+1; it != nums.cend(); ++it)
        {
            maxendinghere = std::max(maxendinghere+*it, *it);
            maxsofar = std::max(maxsofar, maxendinghere);
        }
        return maxsofar;
    }
};
