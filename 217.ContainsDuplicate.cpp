/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

bool containsDuplicate(std::vector<int>& nums)
{
    if (nums.empty()) return false;

    std::unordered_set<int> s;
    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
        auto ret = s.emplace(*it);
        if (!ret.second)
            return true;
    }
    return false;
}

// An elegant code in C++
bool containsDuplicate(std::vector<int>& nums) {
    return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
}
