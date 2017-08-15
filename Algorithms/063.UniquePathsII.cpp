/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;

    const int rows = obstacleGrid.size();
    const int cols = obstacleGrid[0].size();

    std::vector<int> paths(rows*cols, 0);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int index = i*cols + j;
            if (obstacleGrid[i][j] == 1)
            {
                paths[index] = 0;
            }
            else
            {
                if (i >= 1 && j >= 1)
                    paths[index] = paths[index - cols] + paths[index - 1];
                else if (i >= 1 && j == 0)
                {
                    paths[index] = paths[index - cols];
                }
                else if (i == 0 && j >= 1)
                {
                    paths[index] = paths[index - 1];
                }
                else
                {
                    paths[index] = 1;
                }
            }
        }
    }

    return paths.back();
}

};



int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;

    const int rows = obstacleGrid.size();
    const int cols = obstacleGrid[0].size();

    std::vector<std::vector<int>> paths(obstacleGrid);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (obstacleGrid[i][j] == 1)
            {
                paths[i][j] = 0;
            }
            else
            {
                if (i >= 1 && j >= 1)
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
                else if (i >= 1 && j == 0)
                {
                    paths[i][j] = paths[i-1][j];
                }
                else if (i == 0 && j >= 1)
                {
                    paths[i][j] = paths[i][j-1];
                }
                else
                {
                    paths[i][j] = 1;
                }
            }
        }
    }

    return paths[rows-1][cols-1];
}
