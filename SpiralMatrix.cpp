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

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    vector<int> result;

    if (matrix.size() == 0) return result;
    
    int row = (int)matrix.size();
    int column = (int)matrix[0].size();
    int count = row*column;
    int K = std::min(row, column)/2;
    for (int k = 0; k < K; ++k)
    {
        for (int i = k; i < k+column-2*k-1; ++i)
        {
            result.push_back(matrix[k][i]);
            count--;
        }
        
        for (int i = k; i < k+row-2*k-1; ++i)
        {
            result.push_back(matrix[i][k+column-2*k-1]);
            count--;
        }
        
        for (int i = k+column-2*k-1; i > k; --i)
        {
            result.push_back(matrix[k+row-2*k-1][i]);
            count--;
        }
        
        for (int i = k+row-2*k-1; i > k; --i)
        {
            result.push_back(matrix[i][k]);
            count--;
        }
    }
    
    if (count > 0)
    {
        if (row > column)
        {
            for (int i = column/2; i < row-column/2; ++i)
                result.push_back(matrix[i][column/2]);
        }
        else if (row < column)
        {
            for (int i = row/2; i < column-row/2; ++i)
                result.push_back(matrix[row/2][i]);
        }
        else if (row == column && row%2 == 1)
        {
            result.push_back(matrix[row/2][row/2]);
        }
    }
    
    return result;
}
