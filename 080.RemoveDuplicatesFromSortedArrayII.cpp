/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(std::vector<int>& nums)
{
    if (nums.size() <= 2) return (int)nums.size();
    
    int i = 0, j = 0;
    int k = 0;
    for (int iEnd = (int)nums.size(); i < iEnd; ++i)
    {
        if (nums[i] != nums[j])
        {
            nums[k++] = nums[j];
            if (i-j >= 2)
                nums[k++] = nums[j];
            j = i;
        }
    }
    
    // handle the tail elems
    nums[k++] = nums[j];
    if (i-j >= 2)
        nums[k++] = nums[j];

    return k;
}
