class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Buy and sell pointers
        int left = 0, right = 1;
        int maxP = 0;

        while (right < prices.size()) {
            // If the transaction is profitable
            if (prices[left] < prices[right]) {
                // Find profit and update max if needed
                int profit = prices[right] - prices[left];
                maxP = max(maxP, profit);
            }
            // Shift left to right (found lower price)
            else left = right;
            // Move right regardless to check next profit
            right++;
        }

        return maxP;
    }
};
