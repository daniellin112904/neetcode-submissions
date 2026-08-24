class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Vector to hold result
        vector<int> result(nums.size());
        // Prefix of first val = 1 (no prefix)
        result[0] = 1;

        // Calculate prefix
        int prefix = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefix *= nums[i - 1];
            result[i] = prefix;
        }

        // Calculate postfix
        int postfix = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            postfix *= nums[i + 1];
            result[i] *= postfix;
        }
        return result;
    }
};
