/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

std::vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) return {};

    std::vector<int> result(rowIndex+1, 1);
    for (int i = 2; i <= rowIndex; ++i) {
        for (int j = i-1; j > 0; --j) {
            result[j] = result[j] + result[j-1];
        }
    }
    return result;
}
