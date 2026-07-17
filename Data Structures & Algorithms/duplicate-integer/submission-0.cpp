class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // set to store seen values
        std::unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            // return true if value already appeared
            if (seen.contains(nums[i]))
                return true;
            // else insert into set
            else seen.insert(nums[i]);
        }
        // return false if gone through whole array without duplicate
        return false;
    }
};