/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> U;
    for (int i = 0, iEnd = (int)nums.size(); i < iEnd; ++i)
    {
        if (U.find(nums[i]) != U.end())
            U[nums[i]]++;
        else
            U.emplace(std::make_pair(nums[i], 1));
    }
    
    std::vector<std::pair<int, int>> V;
    for (auto it = U.cbegin(); it != U.cend(); ++it)
    {
        V.emplace_back(*it);
    }
    
    std::make_heap(V.begin(), V.end(),
                   [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                   { return a.second < b.second; });
    
    std::vector<int> result;
    while (k-- > 0)
    {
        std::pop_heap(V.begin(), V.end(),
                      [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                      { return a.second < b.second; });
        result.emplace_back(V.back().first);
        V.pop_back();
    }
    
    return result;
}
