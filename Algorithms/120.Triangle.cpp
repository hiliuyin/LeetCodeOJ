/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

// Using O(n^2) extra space
int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    if (triangle.empty() || triangle.front().empty())
        return 0;

    std::vector<std::vector<int>> sums(triangle);
    for (auto r = 1, rEnd = (int)triangle.size(); r < rEnd; ++r)
    {
        for (auto c = 0, cEnd = (int)triangle[r].size(); c < cEnd; ++c)
        {
            if (c == 0)
                sums[r][c] = sums[r - 1][c] + triangle[r][c];
            else if (c > 0 && c < cEnd - 1)
                sums[r][c] = std::min(sums[r - 1][c] + triangle[r][c], sums[r - 1][c - 1] + triangle[r][c]);
            else
                sums[r][c] = sums[r - 1][c - 1] + triangle[r][c];
        }
    }

    return *std::min_element(sums.back().begin(), sums.back().end());
}
