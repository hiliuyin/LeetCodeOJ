/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/

int minPathSum(std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid.front().empty()) return 0;

    const int rows = grid.size();
    const int cols = grid.front().size();
    std::vector<std::vector<int>> sums(grid);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i > 0 && j > 0)
                sums[i][j] = std::min(sums[i - 1][j] + grid[i][j], sums[i][j - 1] + grid[i][j]);
            else if (i == 0 && j > 0)
                sums[i][j] = sums[i][j - 1] + grid[i][j];
            else if (i > 0 && j == 0)
                sums[i][j] = sums[i - 1][j] + grid[i][j];
            else
                sums[i][j] = grid[i][j];
        }
    }

    return sums.back().back();
}
