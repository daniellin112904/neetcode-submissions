class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Output array
        vector<int> answer(n);
        // No prefix => set to 1
        answer[0] = 1;

        // Calculate prefix
        int prefix = 1;
        for (int i = 1; i < n; i++) {
            prefix *= nums[i-1];
            answer[i] = prefix;
        }

        // Calculate postfix
        int postfix = 1;
        for (int i = n - 2; i >= 0; i--) {
            postfix *= nums[i+1];
            answer[i] *= postfix;
        }

        return answer;
    }
};
