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
    
    int k = 1;
    for (int i = 1, iEnd = (int)nums.size(), count = 1; i < iEnd; ++i)
    {
        if (nums[i] == nums[i-1])
        {
            count++;
            if (count <= 2)
                nums[k++] = nums[i];
        }
        else
        {
            nums[k++] = nums[i];
            count = 1;
        }
    }

    return k;
}
