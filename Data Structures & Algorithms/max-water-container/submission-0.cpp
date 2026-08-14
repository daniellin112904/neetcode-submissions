class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int result = 0;

        while (left < right) {
            // area = length (r - l) * min of two heights (no leak)
            int area = (right - left) *
             min(heights[left], heights[right]);
            // Update result if greater area
            result = max(result, area);
            if (heights[left] < heights[right]) left++;
            else if (heights[left] > heights[right]) right--;
            // Pick 1 to move if equal (can be condensed with elif)
            else right--;
        }

        return result;
    }
};
