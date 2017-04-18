// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.

int maxSubArray(vector<int>& nums) {
    int maxendinghere = nums[0], maxsofar = nums[0];
    for (int i = 1, iEnd = nums.size(); i < iEnd; ++i) {
        maxendinghere = std::max(maxendinghere + nums[i], nums[i]);
        maxsofar = std::max(maxsofar, maxendinghere);
    }
    return maxsofar;
}
