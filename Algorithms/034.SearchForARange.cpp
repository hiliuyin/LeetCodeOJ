/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    if (nums.empty()) return {-1, -1};
    
    int rangeLow = -1;
    
    int low = 0, high = (int)nums.size()-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid] == target)
        {
            rangeLow = mid;
            high = mid-1;
        }
        else if (nums[mid] > target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    if (rangeLow == -1) return {-1, -1};
    
    int rangeHigh = rangeLow;
    low = rangeLow, high = (int)nums.size()-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid] == target)
        {
            rangeHigh = mid;
            low = mid+1;
        }
        else if (nums[mid] > target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return {rangeLow, rangeHigh};
}
