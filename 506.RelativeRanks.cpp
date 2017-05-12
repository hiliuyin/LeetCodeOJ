/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.

Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

// solution 1: use vector
vector<string> findRelativeRanks(vector<int>& nums) {
    std::vector<string> res(nums.size(), "");
    std::vector<std::pair<int, int>> v;
    for (int i = 0, iEnd = nums.size(); i < iEnd; ++i) {
        v.emplace_back(nums[i], i);
    }
    
    std::sort(v.begin(), v.end(), 
        [](const pair<int, int>& p1, const pair<int, int>& p2){return p1.first > p2.first;});
    
    for (int i = 0, iEnd = v.size(); i < iEnd; ++i) {
        int index = v[i].second;
        switch (i) {
        case 0: res[index] = "Gold Medal"; break;
        case 1: res[index] = "Silver Medal"; break;
        case 2: res[index] = "Bronze Medal"; break;
        default: res[index] = std::to_string(i+1); break;
        }
    }
    return res;
}
