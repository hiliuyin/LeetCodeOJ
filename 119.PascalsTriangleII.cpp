/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

std::vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) return {};
    
    std::vector<int> row(rowIndex+1, 1);
    for (int i = 1; i < rowIndex; ++i)
        for (int j = i; j >= 1; --j)
            row[j] = row[j]+row[j-1];
    
    return row;
}
