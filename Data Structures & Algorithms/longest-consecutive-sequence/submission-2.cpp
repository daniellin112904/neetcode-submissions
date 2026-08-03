class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Set to hold copy of vector
        unordered_set<int> copy(nums.begin(), nums.end());
        int longest = 0;
        for (int i: copy) {
            // If its the start of a sequence
            if (!(copy.contains(i - 1))) {
                int length = 0;
                // Count sequence length
                while (copy.contains(i + length))
                    length++;
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
