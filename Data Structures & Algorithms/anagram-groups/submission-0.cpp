class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hashtable to hold sorted keys
        std::unordered_map<string, vector<string>> groups;

        for (int i = 0; i < strs.size(); i++) {
            // copy string to sort for key
            string key = strs[i];
            sort(key.begin(), key.end());

            // add original string to key holding all anagrams
            groups[key].push_back(strs[i]);
        }

        vector<vector<string>> results;
        // for all key, value in hashtable: append vector holding values to final result
        for (auto pair: groups) {
            results.push_back(pair.second);
        }

        return results;
    }
};
