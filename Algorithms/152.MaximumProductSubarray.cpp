/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

int maxProduct(std::vector<int>& nums)
{
    int maxEndinghere = nums[0];
    int minEndinghere = nums[0];
    int maxSofar = nums[0];
    for (int i = 1, iEnd = (int)nums.size(); i < iEnd; ++i)
    {
        int a = maxEndinghere*nums[i];
        int b = minEndinghere*nums[i];
        
        maxEndinghere = std::max(std::max(a, b), nums[i]);
        minEndinghere = std::min(std::min(a, b), nums[i]);
        
        maxSofar = std::max(maxEndinghere, maxSofar);
    }
    return maxSofar;
}
