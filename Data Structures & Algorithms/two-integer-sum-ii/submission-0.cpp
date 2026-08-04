class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Pointers to start and end of array
        int left = 0;
        int right = numbers.size() - 1;
        int sum;

        while (left < right) {
            // Calculate current sum
            sum = numbers[left] + numbers[right];
            // If sum too small, move left to increase
            if (sum < target) left++;
            // Move right to descrease
            else if (sum > target) right--;
            // return solution (exactly one solution, 1-index)
            else return {left + 1, right + 1};
        }
        return {};
    }
};
