/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    if (nums.size() < 4) return {};

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
    for (int i = 0, iEnd = nums.size() - 3; i < iEnd; ++i)
    {
        if (nums[i] * 4 > target) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1, jEnd = nums.size() - 2; j < jEnd; ++j)
        {
            if (nums[j] * 3 > target - nums[i]) break;
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            for (int k = j + 1, kEnd = nums.size() - 1; k < kEnd; ++k)
            {
                if (nums[k] * 2 > target - nums[i] - nums[j]) break;
                if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                auto search = binarySearch(k + 1, nums.size() - 1, target - nums[i] - nums[j] - nums[k]);
                if (search != -1)
                {
                    result.emplace_back(std::vector<int>({ nums[i], nums[j], nums[k], nums[search] }));
                }
            }
        }
    }
    return result;
}
