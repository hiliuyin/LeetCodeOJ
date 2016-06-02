// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
// Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
// Given target = 3, return true.

class Solution {
public:
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    auto bSearchRow = [&matrix, target]() -> int
    {
        int low = 0, high = (int)matrix.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) return mid;
            else if (matrix[mid][0] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    };

    int row = bSearchRow();
    if (row < 0) return false;

    auto bSearchColumn = [target](const std::vector<int>& matrixRow) -> bool
    {
        int low = 0, high = (int)matrixRow.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrixRow[mid] == target) return true;
            else if (matrixRow[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    };

    return bSearchColumn(matrix[row]);
}
};
