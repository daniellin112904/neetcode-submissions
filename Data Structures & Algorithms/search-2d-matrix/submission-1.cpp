class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get rows and columns size
        int rows = matrix.size();
        int cols = matrix[0].size(); // All cols same size

        // Row pointers
        int top = 0, bot = rows - 1;

        // Run binary search on rows
        while (top <= bot) {
            int row = (top + bot) / 2;
            // Target > last value in this row (increment)
            if (target > matrix[row][cols - 1]) top = row + 1;
            // Target < last value in this row
            else if (target < matrix[row][0]) bot = row - 1;
            // Target could be in this row
            else break;
        }
        // No valid row found
        if (top > bot) return false;

        int row = (top + bot) / 2;
        int left = 0, right = cols - 1;

        // Run binary search on row
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] < target) left = mid + 1;
            else if (matrix[row][mid] > target) right = mid - 1;
            else return true;
        }
        return false;
    }
};
