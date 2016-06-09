/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

std::vector<std::vector<int>> generateMatrix(int n) {
    if (n <= 0) return {};
    
    std::vector<int> row(n);
    std::vector<std::vector<int>> result(n, row);
    
    for (int k = 0, kEnd = (n+1)/2, val = 1; k < kEnd; ++k)
    {
        for (int i = k, iEnd = n-k; i < iEnd; ++i)
            result[k][i] = val++;
        
        for (int i = k+1, iEnd = n-k; i < iEnd; ++i)
            result[i][n-k-1] = val++;
        
        for (int i = n-k-2, iEnd = k-1; i > iEnd; --i)
            result[n-k-1][i] = val++;
        
        for (int i = n-k-2, iEnd = k; i > iEnd; --i)
            result[i][k] = val++;
    }
    
    return result;
}
