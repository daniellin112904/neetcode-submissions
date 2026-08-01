class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to hold seen values
        unordered_map <int, int> seen;
        int diff;

        for (int i = 0; i < nums.size(); i++) {
            // Calculate current difference
            diff = target - nums[i];
            // If diff in map, return current and diff index
            if (seen.contains(diff)) return {seen[diff], i};
            // Else add current value and index to map
            else seen[nums[i]] = i;
        }

        return {};
    }
};
