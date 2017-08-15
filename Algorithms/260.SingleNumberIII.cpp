/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

// Solution 1: O(n) runtime complexity with O(n) space complexity.
std::vector<int> singleNumber(std::vector<int>& nums) {
    std::vector<int> result;
    std::unordered_map<int, int> M;
    for (auto&& num : nums) {
        auto it = M.find(num);
        if (it == M.end())
            M[num] = 1;
        else
            M[num]++;
    }
    
    for (auto&& m : M) {
        if (m.second == 1)
            result.emplace_back(m.first);
    }
    
    return result;
}

// Solution 2: O(n) runtime complexity with constant space complexity
std::vector<int> singleNumber(std::vector<int>& nums) {
    int val = 0;
    for (const auto& num : nums) {
        val ^= num;
    }
    val &= (~(val-1));
    int one = 0, other = 0;
    for (const auto& num : nums) {
        if ((num & val) != 0)
            one ^= num;
        else
            other ^= num;
    }
    return {one, other};
}


