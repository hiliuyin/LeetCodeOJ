/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
void setZeroes(std::vector<std::vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) return;

    const int rows = matrix.size();
    const int cols = matrix[0].size();

    bool needSetRow0 = false, needSetCol0 = false;
    for (auto i = 0; i < rows; ++i)
    {
        for (auto j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0) needSetRow0 = true;
                if (j == 0) needSetCol0 = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (auto i = 1; i < rows; ++i)
    {
        for (auto j = 1; j < cols; ++j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (needSetRow0)
    {
        for (auto i = 0; i < cols; ++i)
            matrix[0][i] = 0;
    }
    
    if (needSetCol0)
    {
        for (auto i = 0; i < rows; ++i)
            matrix[i][0] = 0;
    }
}

};
