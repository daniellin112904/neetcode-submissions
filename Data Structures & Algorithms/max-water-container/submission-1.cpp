class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int result = 0;
        
        while (left < right) {
            // Length (r - l) * min of two heights (avoid leak)
            int area = (right - left) * min(heights[left], heights[right]);
            // Update result if area greater
            result = max(result, area);
            // Update pointers
            if (heights[left] < heights[right]) left++;
            // Can update either if equal
            else right--;
        }

        return result;
    }
};
