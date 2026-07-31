class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Pointer to start, end, and middle of boundary
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        // Loop until boundary doesn't exist (<= in case only 1 value)
        while(start <= end) {
            // Recalculate mid
            mid = (start + end) / 2;
            if (nums[mid] == target) return mid;

            // Set new boundary if target not found
            else if (target < nums[mid]) end = mid - 1;
            else if (target > nums[mid]) start = mid + 1;
        }

        return -1;
    }
};
