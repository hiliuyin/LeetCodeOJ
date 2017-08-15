/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> s(nums1.begin(), nums1.end());
    
    std::vector<int> result;
    for (const auto& num : nums2) {
        if (s.find(num) != s.end()) {
            result.emplace_back(num);
            s.erase(num);
        }
    }
    return result;
}

