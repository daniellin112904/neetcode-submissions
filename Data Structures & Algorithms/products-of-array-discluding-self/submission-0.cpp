class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // size of array
        int n = nums.size();
        
        // arrays to hold prefix, postfix, and answer
        vector<int> pre(n);
        vector<int> post(n);
        vector<int> ans(n);

        // prefix products        
        pre[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i-1] * nums[i-1];
        }

        // postfix products
        post[n-1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            post[i] = post[i+1] * nums[i+1];
        }

        // calculate final answer
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = pre[i] * post[i];
        }

        return ans;
    }
};
