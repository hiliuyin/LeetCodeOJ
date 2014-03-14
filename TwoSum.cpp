// Two Sum
// Given an array of integers, find two numbers such that they add up to a specific target number.
// 
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
// 
// You may assume that each input would have exactly one solution.
// 
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

//
// sort the array first, then use binary search to find the answer
//
bool
BinarySearch(std::vector<int>::iterator begin,
             std::vector<int>::iterator last,
             int target,
             std::vector<int>::iterator &founded)
{
    while (begin != last)
    {
        std::vector<int>::iterator mid = begin + (last - begin)/2;
        
        if (*mid == target)
        {
            founded = mid;
            return true;
        }
        else if (*mid > target)
        {
            last = mid;
        }
        else // *mid < target
        {
            begin = mid+1;
        }
    }
    return false;
}

std::vector<int> twoSum(std::vector<int> &numbers, int target)
{
    std::vector<int> result;

    std::vector<int> numbersCopy(numbers);
    
    size_t size = numbersCopy.size();
    if (size == 0 || size == 1) return result;
    
    std::sort(numbersCopy.begin(), numbersCopy.end());
    
    bool founded = false;
    std::vector<int>::iterator first, second;
    for (std::vector<int>::iterator it = numbersCopy.begin(); it != numbersCopy.end(); ++it)
    {
        if (*it <= target)
        {
            first = it;
            founded = BinarySearch(it+1, numbersCopy.end(), target-*it, second);
            
            if (founded)
                break;
        }
        else
        {
            break;
        }
    }

    if (founded)
    {
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (*second == numbers[i] || *first == numbers[i])
                result.push_back(i+1);
        }
    }

    return result;
}
