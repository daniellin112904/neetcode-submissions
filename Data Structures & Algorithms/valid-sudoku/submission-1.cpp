class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Maps to store seen values
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        unordered_map<int, unordered_set<int>> boxes;

        // Loop through board (9x9)
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                // Skip if empty
                char val = board[r][c];
                // Key values for each square
                int key = (r/3)*3 + (c/3);

                // Return false if duplicate (in map)
                if (rows[r].count(val) || cols[c].count(val) || boxes[key].count(val)) return false;

                // Add value to map
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[key].insert(val);
            }
        }
        return true;
    }
};
