class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // copy vector into set for O(1) search
        unordered_set<int> copy(nums.begin(), nums.end());
        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            // if its the beginning of a sequence (no -1)
            if (!(copy.contains(nums[i] - 1))) {
                int length = 0;
                // while sequence exist
                while (copy.contains(nums[i] + length)) {
                    length++;
                }
                // take max of longest and current length
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
