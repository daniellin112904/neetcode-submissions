class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Vector to store result
        vector<int> result(n);
        // default prefix to 1
        result[0] = 1;

        // calculate prefix
        int prefix = 1;
        for (int i = 1; i < n; i++) {
            prefix *= nums[i-1];
            result[i] = prefix;
        }

        // calculate postfix
        int postfix = 1;
        for (int i = n - 2; i >= 0; i--) {
            postfix *= nums[i+1];
            result[i] *= postfix;
        }

        return result;
    }
};
