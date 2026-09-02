class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int result = nums[left];

        while (left <= right) {
            // Section we're in is already sorted (return first value)
            if (nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }

            int mid = (left + right) / 2;
            // Update result if needed after finding new min
            result = min(result, nums[mid]);

            // If its greater, its in rotated (greater) section, search right
            // >= because middle pointer could be leftmost value
            if (nums[mid] >= nums[left]) left = mid + 1;
            // If in right sorted portion, everything right is greater, look for a smaller number on the left
            else right = mid - 1;
        }
        return result;
    }
};
