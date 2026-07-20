class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hashmap to store key and all anagrams
        std::unordered_map<string, vector<string>> anagrams;

        for (int i = 0; i < strs.size(); i++) {
            // sort string for key
            string key = strs[i];
            sort(key.begin(), key.end());
            // push original string into value with sorted key
            anagrams[key].push_back(strs[i]);
        }

        // vector to store grouped anagrams
        vector<vector<string>> grouped;
        for (auto [key, value]: anagrams)
            grouped.push_back(value);
        
        return grouped;
    }
};
