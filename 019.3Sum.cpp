/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    if (nums.size() < 3) return{};

    std::sort(nums.begin(), nums.end());
    auto binarySearch = [&nums](int low, int high, int target) -> int
    {
        while (low <= high)
        {
            int med = low + (high - low) / 2;
            if (nums[med] == target) return med;
            else if (nums[med] > target) high = med - 1;
            else low = med + 1;
        }
        return -1;
    };

    std::vector<std::vector<int>> result;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i)
    {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < iEnd; ++j)
        {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            auto search = binarySearch(j+1, iEnd - 1, 0 - nums[i] - nums[j]);
            if (search != -1)
            {
                result.emplace_back(std::vector<int>({ nums[i], nums[j], nums[search] }));
            }
        }
    }
    return result;
}
