// Spiral Matrix
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// 
// For example,
// Given the following matrix:
// 
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].
//

class Solution {
public:
std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    if (matrix.empty() || matrix.back().empty()) return {};
    
    const int rows = (int)matrix.size();
    const int cols = (int)matrix.back().size();
    const int totalCount = rows*cols;
    std::vector<int> result;
    
    for (int r = 0, c = 0, rEnd = (rows+1)/2, cEnd = (cols+1)/2, count = 0;
         (r < rEnd || c < cEnd) && count < totalCount; ++r, ++c)
    {
        for (int i = c, iEnd = cols-c; i < iEnd && count < totalCount; ++i)
        {
            result.emplace_back(matrix[r][i]);
            count++;
        }
        
        for (int i = r+1, iEnd = rows-r; i < iEnd && count < totalCount; ++i)
        {
            result.emplace_back(matrix[i][cols-c-1]);
            count++;
        }
        
        for (int i = cols-c-2; i >= c && count < totalCount; --i)
        {
            result.emplace_back(matrix[rows-r-1][i]);
            count++;
        }
        
        for (int i = rows-r-2; i > r && count < totalCount; --i)
        {
            result.emplace_back(matrix[i][c]);
            count++;
        }
    }
    
    return result;
}
};
