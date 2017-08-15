/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    std::function<void(vector<int>, int)> helper = [&](vector<int> v, int k) {
        if (k == v.size()) {
            res.emplace_back(v);
            return;
        }
        
        for (int i = k, iEnd = v.size(); i < iEnd; ++i) {
            if (i != k && v[i] == v[k]) continue;
            std::swap(v[i], v[k]);
            helper(v, k+1);
        }
    };

    helper(nums, 0);
    return res;
}
