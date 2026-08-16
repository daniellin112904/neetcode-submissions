class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        // Pointers
        int left = 0, right = height.size() - 1;
        // Store max
        int lmax = height[left], rmax = height[right];
        int result = 0;

        while (left < right) {
            // Update smaller pointer
            if (height[left] < height[right]) {
                left++;
                // Find new max (If current height is new max, no water can be stored, so no need to check for negative)
                lmax = max(lmax, height[left]);
                // Increment result with water stored
                result += lmax - height[left];
            }
            // If equal, can increment either
            else {
                right--;
                rmax = max(rmax, height[right]);
                result += rmax - height[right];
            }
        }
        return result;
    }
};
