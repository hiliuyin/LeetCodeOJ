// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<std::size_t> paths(m*n, 1);
        
        for (vector<std::size_t>::size_type i = 1; i < m; ++i)
        {
            for (vector<std::size_t>::size_type j = 1; j < n; ++j)
            {
                paths[i*n+j] = paths[(i-1)*n+j] + paths[i*n+j-1];
            }
        }
        return paths.back();
    }
};
