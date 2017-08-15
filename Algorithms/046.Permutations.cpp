/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

std::vector<std::vector<int>> permute(std::vector<int>& nums)
{
    if (nums.empty()) return{};

    std::function<void(std::vector<std::vector<int>>&, std::vector<int>&, int, int)> permuteHelper =
        [&](std::vector<std::vector<int>> &result, std::vector<int> &num, int begin, int end)
    {
        if (begin > end)
        {
            result.emplace_back(num);
            return;
        }

        permuteHelper(result, num, begin, end - 1);
        for (int i = begin; i <= end - 1; ++i)
        {
            std::swap(num[i], num[end]);
            permuteHelper(result, num, begin, end - 1);
            std::swap(num[i], num[end]);
        }
    };

    std::vector<std::vector<int>> result;
    permuteHelper(result, nums, 0, nums.size() - 1);

    return result;
}

// Another more clear recursive code
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    
    std::function<void(int)> helper = [&](int k) {
        if (k == nums.size())
            res.emplace_back(nums);
        
        for (int i = k, iEnd = nums.size(); i < iEnd; ++i) {
            std::swap(nums[k], nums[i]);
            helper(k+1);
            std::swap(nums[k], nums[i]);
        }
    };
    
    helper(0);
    return res;
}
