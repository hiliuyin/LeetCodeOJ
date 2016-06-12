/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    if (nums1.empty() || nums2.empty()) return {};
    
    std::vector<int> result;
    std::unordered_set<int> s;
    for (auto it = nums1.cbegin(); it != nums1.cend(); ++it)
    {
        s.emplace(*it);
    }
    
    for (auto it = nums2.cbegin(); it != nums2.cend(); ++it)
    {
        auto search = s.find(*it);
        if (search != s.end())
        {
            result.emplace_back(*it);
            s.erase(search);
        }
    }
    return result;
}

