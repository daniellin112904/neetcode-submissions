class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Vector of vectors to hold result
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // Continue if duplicate
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // Use two pointer to solve for twosum (2sum II)
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else {
                    // Append solution to result vector
                    result.push_back({nums[i], nums[left],
                     nums[right]});
                    // Move pointer to look for more solutions
                    left++;
                    while (nums[left] == nums[left-1] &&
                     left < right)
                        left++;
                }
                
            }

        }
        return result;
    }
};
