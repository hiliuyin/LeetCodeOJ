/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

vector<vector<int>> generate(int numRows) {
     if (numRows <= 0) return {};
     vector<int> row{1};
     vector<vector<int>> result{row};
     for (int i = 1; i < numRows; ++i) {
        result.emplace_back(row);
        for (int j = 1; j < i; ++j) {
            result[i].emplace_back(result[i-1][j-1] + result[i-1][j]);
        }
        result[i].emplace_back(1);
    }
    return result;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    for (int i = 0; i < numRows; ++i) {
        result[i].resize(i+1);
        result[i][0] = 1;
        result[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}
