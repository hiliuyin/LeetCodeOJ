// Combination Sum II 
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// 
// Each number in C may only be used once in the combination.
// 
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
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
        
        for (int i = start; i <= last; ++i)
        {
            if (val+candidates[i] > target)
                break;
                
             if (i != start && candidates[i] == candidates[i-1])
                continue;
                
            v.emplace_back(candidates[i]);
            helper(i+1, last, val+candidates[i]);
            v.pop_back();
        }
    };
    
    helper(0, (int)candidates.size()-1, 0);
    return result;
}

