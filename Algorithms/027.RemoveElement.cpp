/*
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3
Your function should return length = 2, with the first two elements of nums being 2.
*/

int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;
    
    int i = 0, j = nums.size()-1;
    while (i <= j) {
        if (nums[i] == val) {
            while (j >= 0 && nums[j] == val) j--;
            if (i > j) break;
            std::swap(nums[i++], nums[j--]);
        }
        else {
            i++;
        }
    }
    return j+1;
}
