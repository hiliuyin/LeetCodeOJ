/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
    if (candidates.empty()) return {};
    
    std::sort(candidates.begin(), candidates.end());
    
    std::vector<std::vector<int>> result;
    std::vector<int> v;
    
    std::function<void(int, int, int)> helper =
    [&](int start, int last, int val)
    {
        if (val == target)
        {
            result.emplace_back(v);
        }
        else if (val > target)
        {
            return;
        }
        
        for (auto i = start; i <= last; ++i)
        {
            if (val+candidates[i] > target)
                break;

            v.emplace_back(candidates[i]);
            helper(i, last, val+candidates[i]);
            v.pop_back();
        }
    };
    
    helper(0, (int)candidates.size()-1, 0);

    return result;
}
