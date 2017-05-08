/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?
*/

// Solution 1: using std::swap
void rotate(std::vector<int>& nums, int k) {
    if (nums.size() < 1 || k <= 0) return;
    auto rotateHelper = [](std::vector<int>& nums, int begin, int end) {
        while (begin < end) {
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

 // Solution 2:
 // How to rotate [1,2,3,4,5,6,7] to [5,6,7,1,2,3,4]?
 // [1->4], [4->7], [7->3], [3->6], [6->2], [2->5], [5->1]
 void rotate(vector<int>& nums, int k) {
    if (nums.size() <= 1 || k <= 0) return;
    const int sz = nums.size();
    k %= sz;
        
    int origin = 0;
    int from = 0, to = k;
    int temp = nums[from];
    for (int i = 0; i < sz; ++i) {
        std::swap(temp, nums[to]);
        from = to;
        if (from == origin) {
            origin++;
            from = origin;
            temp = nums[from];
        }
        to = (from + k) % sz;
    }
}
