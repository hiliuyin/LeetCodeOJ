// 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// 
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4},
// 
// A solution set is:
// (-1, 0, 1)
// (-1, -1, 2)

int binarySearch(vector<int> &num, int start, int last, int target)
{
    while (start <= last)
    {
        int mid = (start+last)/2;
        if (num[mid] == target) return mid;
        else if (num[mid] > target) last = mid-1;
        else start = mid+1;
    }
    return -1;
}

void twoSum(vector<vector<int>> &result, vector<int> &num, int start, int last, int target)
{
    vector<int> v;
    v.push_back(0-target);
    
    for (int i = start; i <= last; ++i)
    {
        if (i != start && num[i] == num[i-1]) // avoid the duplicated combination
            continue;
        
        int index = binarySearch(num, i+1, last, target-num[i]);
        if (index != -1)
        {
            v.push_back(num[i]);
            v.push_back(num[index]);
            result.push_back(v);
            v.pop_back();
            v.pop_back();
        }
    }
}

vector<vector<int>> threeSum(vector<int> &num)
{
    vector<vector<int>> result;
    
    if (num.size() == 0) return result;
    
    std::sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); ++i)
    {
        if (num[i] > 0)
            break;
        if (i > 0 && num[i] == num[i-1]) // avoid the duplicated combination
            continue;
     
        twoSum(result, num, i+1, (int)num.size()-1, 0-num[i]);
    }
    
    return result;
}
