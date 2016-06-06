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

std::vector<std::vector<int>> combine(int n, int k)
{
    if (n <= 0 || k <= 0) return{};

    std::function<void(std::vector<std::vector<int>>&, std::vector<int>, int, int, int)>
        helper = [&](std::vector<std::vector<int>> &result, std::vector<int> vi, int start, int n, int k)
    {
        if (k == 0)
        {
            result.emplace_back(vi);
            return;
        }
        for (int i = start; i <= n - k + 1; ++i)
        {
            vi.emplace_back(i);
            helper(result, vi, i + 1, n, k - 1);
            vi.pop_back();
        }
    };

    std::vector<std::vector<int>> result;
    std::vector<int> vi;
    helper(result, vi, 1, n, k);

    return result;
}
