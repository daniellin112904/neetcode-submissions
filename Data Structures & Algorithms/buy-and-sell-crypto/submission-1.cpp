class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Pointer to buy and sell days
        int buy = 0, sell = 1;
        int maxP = 0;

        while (sell < prices.size()) {
            // If profitable, find profit and update max if needed
            if (prices[buy] < prices[sell]) {
                int profit = prices[sell] - prices[buy];
                maxP = max(maxP, profit);
            }
            // Move buy (found higher value), move sell regardless
            else buy = sell;
            sell++;
        }
        return maxP;
    }
};
