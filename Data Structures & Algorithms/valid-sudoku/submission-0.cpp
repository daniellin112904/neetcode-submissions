class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // map to store rows, columns and squares
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> squares;

        // loop through whole board (9x9)
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // skip if empty
                if (board[r][c] == '.')
                    continue;

                // current value
                char val = board[r][c];
                // key calculation to store squares as unique int from 0-8 (see notion notes)
                int squareKey = (r/3)*3 + (c/3);

                // return false if duplicate
                if (rows[r].count(val) || cols[c].count(val) || squares[squareKey].count(val))
                    return false;

                // add value to map
                rows[r].insert(val);
                cols[c].insert(val);
                squares[squareKey].insert(val);
            }
        }
        // true if no duplicate after whole loop
        return true;
    }
};
