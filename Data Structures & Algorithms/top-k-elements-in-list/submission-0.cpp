class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Hashtable to hold frequency
        std::unordered_map<int, int> freq;

        // Update frequency to hashtable
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        // Vector to store pair of value and its frequency
        vector<pair<int,int>> values;

        // Push all pairs in hashtable into vector
        for (auto pair: freq) {
            values.push_back(pair);
        }

        // Vector to store result
        vector<int> result;
        // Sort by frequency
        sort(values.begin(), values.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        // Push first k integers into result vector
        for (int i = 0; i < k; i++) {
            result.push_back(values[i].first);
        }
        return result;
    }
};
