/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
{
    if (nums1.empty() || nums2.empty()) return {};

    std::vector<int> result;
    std::unordered_multiset<int> s;
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
