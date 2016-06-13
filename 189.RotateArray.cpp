/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?
*/

void rotate(std::vector<int>& nums, int k)
{
    if (nums.size() < 1 || k <= 0) return;

    auto rotateHelper = [](std::vector<int>& nums, int begin, int end)
    {
        while (begin < end)
        {
            std::swap(nums[begin], nums[end]);
            ++begin;
            --end;
        }
    };

    k = k % nums.size();
    rotateHelper(nums, 0, nums.size() - k - 1);
    rotateHelper(nums, nums.size() - k, nums.size() - 1);
    rotateHelper(nums, 0, nums.size() - 1);
}
