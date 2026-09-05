class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            // Return index if mid holds target
            if (nums[mid] == target) return mid;
            // In left (greater) section
            if (nums[mid] >= nums[left]) {
                // greater than mid and less than left (see notion notes for explanation)
                if (target > nums[mid] || target < nums[left]) 
                    left = mid + 1;
                else right = mid - 1;
            }
            // In right section
            else {
                // ^^
                if (target < nums[mid] || target > nums[right])
                    right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
