// 4Sum 
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
// 
// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// 
//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

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

void twoSum(vector<vector<int>> &result, vector<int> &num, int start, int last, int target, vector<int> &v)
{
    for (int i = start; i <= last; ++i)
    {
        if (i != start && num[i] == num[i-1])
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

void threeSum(vector<vector<int>> &result, vector<int> &num, int start, int last, int target, vector<int> &v)
{
    for (int i = start; i <= last; ++i)
    {
        if (i != start && num[i] == num[i-1])
            continue;
     
        v.push_back(num[i]);
        twoSum(result, num, i+1, last, target-num[i], v);
        v.pop_back();
    }
}

vector<vector<int>> fourSum(vector<int> &num, int target)
{
    vector<vector<int>> result;
    
    if (num.size() == 0) return result;
    
    std::sort(num.begin(), num.end());
    
    vector<int> v;
    for (int i = 0; i < num.size(); ++i)
    {
        if (i != 0 && num[i] == num[i-1])
            continue;

        v.push_back(num[i]);
        threeSum(result, num, i+1, (int)num.size()-1, target-num[i], v);
        v.pop_back();
    }
    
    return result;
}
