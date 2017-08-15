/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

// Greedy Algorithm: Always calculate the furthest index in every jump
int jump(std::vector<int>& nums)
{
    if (nums.empty() || nums.size() == 1) return 0;
    
    int jumps = 1;
    for (int takeOffIndex = 0, furthestSofar = nums[0];;)
    {
        if (furthestSofar >= nums.size()-1)
            break;

        jumps++;
        for (int i = takeOffIndex+1, iEnd = furthestSofar; i <= iEnd; ++i)
        {
            int furthestEndingHere = i+nums[i];
            if (furthestEndingHere > furthestSofar)
            {
                furthestSofar = furthestEndingHere;
                takeOffIndex = i;
            }
        }
    }
    return jumps;
}
