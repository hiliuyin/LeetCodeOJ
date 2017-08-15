/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

vector<vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> v;
    std::function<void(int, int)> helper = [&](int beg, int count) {
        if (count == 0) {
            res.emplace_back(v);
        }
        for (int i = beg; i <= n; ++i) {
            v.emplace_back(i);
            helper(i+1, count-1);
            v.pop_back();
        }
    };

    helper(1, k);
    return res;
}
