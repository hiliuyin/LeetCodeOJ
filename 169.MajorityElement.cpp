/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

// Solution 1: sort
int majorityElement(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

// Solution 2: partial sort
int majorityElement(vector<int>& nums) {
    std::nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
    return nums[nums.size()/2];
}

// Solution 3: moore voting algorithm
int majorityElement(vector<int>& nums) {
    int elem;
    int count = 0;
    for (const auto& num : nums) {
        if (count == 0) {
            elem = num;
            count++;
        }
        else {
            num == elem ? count++ : count--;
        }
    }
    return elem;
}
