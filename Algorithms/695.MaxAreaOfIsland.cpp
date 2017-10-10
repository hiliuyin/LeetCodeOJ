/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/

int bfs(const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<int>>& visited,
        int x, int y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid.back().size() || visited[x][y] == 1)
        return 0;
    visited[x][y] = 1;
    if (grid[x][y] == 0) return 0;
    return 1 + bfs(grid, visited, x-1, y) + bfs(grid, visited, x, y-1)
             + bfs(grid, visited, x+1, y) + bfs(grid, visited, x, y+1);
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int maxArea = 0;
    std::vector<std::vector<int>> visited =
        std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid.back().size(), 0));
    for (int x = 0, xEnd = (int)grid.size(); x < xEnd; ++x) {
        for (int y = 0, yEnd = (int)grid[x].size(); y < yEnd; ++y) {
            if (visited[x][y] == 1) continue;
            maxArea = std::max(maxArea, bfs(grid, visited, x, y));
        }
    }
    return maxArea;
}
