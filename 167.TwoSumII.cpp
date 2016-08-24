/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    auto binarySearch = [&numbers](int low, int high, int target) -> int
    {
        while (low <= high)
        {
            int mid = low + (high-low)/2;
            if (numbers[mid] == target) return mid;
            else if (numbers[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    };
    
    for (int i = 0, iEnd = (int)numbers.size(); i < iEnd; ++i)
    {
        auto index = binarySearch(i+1, iEnd-1, target-numbers[i]);
        if (index != -1)
        {
            return {i+1, index+1};
        }
    }
    return {-1, -1};
}
