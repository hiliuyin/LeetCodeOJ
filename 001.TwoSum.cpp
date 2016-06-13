/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    if (nums.empty()) return{};

    std::vector<int> numsCopy(nums);
    std::sort(numsCopy.begin(), numsCopy.end());

    auto bSearch = [&numsCopy](int begin, int last, int val) -> int
    {
        if (begin > last) return -1;
        while (begin <= last)
        {
            int mid = begin + (last - begin) / 2;
            if (numsCopy[mid] == val) return mid;
            else if (numsCopy[mid] > val) last = mid - 1;
            else begin = mid + 1;
        }
        return -1;
    };

    for (int i = 0, iEnd = numsCopy.size(); i < iEnd; ++i)
    {
        int index = bSearch(i+1, iEnd-1, target- numsCopy[i]);
        if (index != -1)
        { 
            auto it1 = std::find(nums.begin(), nums.end(), numsCopy[i]);
            auto it2 = std::find(nums.begin(), nums.end(), numsCopy[index]);
            if (it2 == it1)
                it2 = std::find(it2 + 1, nums.end(), numsCopy[index]);
            return {it1 - nums.begin(), it2 - nums.begin()};
        }
    }
    return{};
}
