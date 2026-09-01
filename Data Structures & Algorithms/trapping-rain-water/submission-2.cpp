class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        // Pointers
        int left = 0, right = height.size() - 1;
        // Max heights
        int lmax = height[left], rmax = height[right];
        int result = 0;

        while (left < right) {
            // Update smaller value
            if (height[left] < height[right]) {
                left++;
                // Find new max and increment water to result
                lmax = max(lmax, height[left]);
                result += lmax - height[left];
            }
            // Can increment either if equal
            else {
                right--;
                rmax = max(rmax, height[right]);
                result += rmax - height[right];
            }
        }
        return result;

    }
};
