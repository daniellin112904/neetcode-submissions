class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Maximum time needed to eat a pile is max value in piles
        // Pointers to perform binary search for minimum speed
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            // current k (middle value)
            int k = (left + right) / 2;
            int hours = 0;
            // for pile in piles
            for (int p: piles) {
                // Calculate hour per pile, take ceil, add to total
                hours += (p + k - 1) / k; // Formula for ceil
            }

            // If all bananas eaten, update min if needed
            if (hours <= h) {
                result = min(result, k);
                right = k - 1; // Look for smaller k
            }
            else left = k + 1;
        }
        return result;
    }
};
