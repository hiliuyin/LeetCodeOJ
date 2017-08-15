// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    
    int prev = nums[0];
    int pos = 1;
    for (int i = 1, iEnd = nums.size(); i < iEnd; ++i) {
        if (nums[i] != prev) {
            nums[pos++] = nums[i];
            prev = nums[i];
        }
    }
    return pos;
}
