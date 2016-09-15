/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
    std::unordered_map<char, int> M;
    for (int i = 0; i < 9; ++i)
        M['1'+i] = 0;
    
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            char ch = board[row][col];
            if (ch == '.') continue;
            if (M[ch] != 0)
                return false;
            M[ch] = 1;
        }
        
        for (int i = 0; i < 9; ++i)
            M['1'+i] = 0;
    }
    
    for (int col = 0; col < 9; ++col)
    {
        for (int row = 0; row < 9; ++row)
        {
            char ch = board[row][col];
            if (ch == '.') continue;
            if (M[ch] != 0)
                return false;
            M[ch] = 1;
        }
        
        for (int i = 0; i < 9; ++i)
            M['1'+i] = 0;
    }
    
    for (int i = 0; i < 9; ++i)
    {
        int row_start = (i/3) * 3;
        int col_start = (i%3) * 3;
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                char ch = board[row_start+row][col_start+col];
                if (ch == '.') continue;
                if (M[ch] != 0)
                    return false;
                M[ch] = 1;
            }
        }
        for (int j = 0; j < 9; ++j)
            M['1'+j] = 0;
    }
    return true;
}
