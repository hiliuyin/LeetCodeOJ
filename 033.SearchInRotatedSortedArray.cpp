/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/

int search(std::vector<int>& nums, int target)
{
    if (nums.empty()) return -1;
    
    int low = 0, high = static_cast<int>(nums.size()-1);
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            if (nums[mid] > nums[high])
            {
                if (target > nums[high])
                    high = mid-1;
                else if (target < nums[high])
                    low = mid+1;
                else
                    return high;
            }
            else
            {
                high = mid-1;
            }
        }
        else // nums[mid] < target
        {
            if (nums[mid] > nums[high])
            {
                low = mid+1;
            }
            else
            {
                if (target > nums[high])
                    high = mid-1;
                else if (target < nums[high])
                    low = mid+1;
                else
                    return high;
            }
        }
    }
    return -1;
}
