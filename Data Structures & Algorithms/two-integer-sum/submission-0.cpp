class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hashtable to hold seen values
        std::unordered_map<int, int> seen;

        // hold current difference
        int diff;
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            // If difference is in hashtable (we have exact number needed)
            if (seen.contains(diff))
                return {seen[diff], i};
            // Append current int and index
            else seen[nums[i]] = i;
        }

        return {};
    }
};
