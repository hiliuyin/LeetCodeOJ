/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Note: The length of the input array will not exceed 20,000.
*/

// Solution 1: HashMap
int findLHS(vector<int>& nums) {
    std::unordered_map<int, int> um;
    for (const auto& num : nums) {
        um[num]++;
    }
    
    int res = 0;
    for (auto it = um.begin(); it != um.end(); ++it) {
        if (um.count(it->first - 1) != 0) {
            res = std::max(res, it->second + um[it->first - 1]);
        }
        if (um.count(it->first + 1) != 0) {
            res = std::max(res, it->second + um[it->first + 1]);
        }
    }
    return res;
}
