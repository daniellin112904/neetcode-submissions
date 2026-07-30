class Solution {
public:
    int search(vector<int>& nums, int target) {
        // pointer to beginning, end, and middle of boundary
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // loop until there is no boundary
        while (left <= right) {
            // calculate mid
            mid = (left + right) / 2;
            if (nums[mid] ==  target) return mid;
            // update boundary
            else if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
        }

        return -1;
    }
};
