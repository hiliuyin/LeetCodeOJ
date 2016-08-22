/*
Follow up for "Search in Rotated Sorted Array":

What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

bool search(vector<int>& nums, int target)
{
    if (nums.empty()) return false;
    
    int low = 0, high = static_cast<int>(nums.size()-1);
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] > target)
        {
            if (nums[mid] > nums[high])
            {
                if (nums[high] > target)
                    low = mid+1;
                else if (nums[high] < target)
                    high = mid-1;
                else
                    return true;
            }
            else if (nums[mid] == nums[high])
            {
                high--;
            }
            else
            {
                high = mid-1;
            }
        }
        else // nums[mid] < target
        {
            if (nums[mid] > nums[high])
                low = mid+1;
            else if (nums[mid] == nums[high])
            {
                high--;
            }
            else
            {
                if (nums[high] > target)
                    low = mid+1;
                else if (nums[high] < target)
                    high = mid-1;
                else
                    return true;
            }
        }
    }
    return false;
}
