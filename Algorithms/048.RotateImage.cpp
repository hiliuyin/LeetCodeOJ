/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

void rotate(std::vector<std::vector<int>>& matrix)
{
    if (matrix.empty() || matrix.back().empty() || matrix.size() == 1) return;
    const int N = (int)matrix.size();
    for (int i = 0, iEnd = (N + 1) / 2; i < iEnd; ++i)
    {
        for (int k = 0, kEnd = N - i * 2 - 1; k < kEnd; ++k)
        {
            std::swap(matrix[i][i + k], matrix[i+k][N-i-1]);
            std::swap(matrix[i][i + k], matrix[N-i-1][N-i-k-1]);
            std::swap(matrix[i][i + k], matrix[N-i-k-1][i]);
        }
    }
}
