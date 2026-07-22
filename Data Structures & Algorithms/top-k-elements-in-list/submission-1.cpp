class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Map to store frequency
        std::unordered_map<int, int> freq;

        // Update frequency
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // vector to store pair of value and its frequency (key + value (freq))
        vector<pair<int, int>> freqPair;
        for (auto [key, value]: freq) {
            freqPair.push_back({key, value});
        }

        // sort using frequency
        sort(freqPair.begin(), freqPair.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        // push k values in result vector after sorting
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqPair[i].first);
        }

        return result;
    }
};
