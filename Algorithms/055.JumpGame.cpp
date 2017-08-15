/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/

bool canJump(std::vector<int>& nums)
{
    if (nums.empty()) return false;

    int furthestIndexSofar = 0;
    for (int i = 0, iEnd = (int)nums.size(); i < iEnd; ++i)
    {
        furthestIndexSofar = std::max(furthestIndexSofar, nums[i]+i);
        if (furthestIndexSofar >= iEnd-1)
            return true;
        else if (furthestIndexSofar == i && nums[i] == 0)
            break;
    }
    return false;
}
