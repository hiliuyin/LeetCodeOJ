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

void doCombine(vector<vector<int>> &result,
               vector<int> &v,
               vector<int> &num,
               int start,
               int target,
               int sum)
{
    if (sum == target)
    {
        result.push_back(v);
    }
    else if (sum > target)
    {
        return;
    }
    else
    {
        for (int i = start; i < num.size(); ++i)
        {
            if (sum+num[i] > target)
                break;
            
            if (i != start && num[i] == num[i-1])  // Since the array is sorted, to avoid the duplicated combination
                continue;

            v.push_back(num[i]);
            doCombine(result, v, num, i+1, target, sum+num[i]);
            v.pop_back();
        }
    }
}
    

vector<vector<int>> combinationSum2(vector<int> &num, int target)
{
    if (num.size() == 0) return {};
    
    vector<vector<int>> result;
    vector<int> v;
    
    std::sort(num.begin(), num.end());
    
    doCombine(result, v, num, 0, target, 0);
    
    return result;
}

