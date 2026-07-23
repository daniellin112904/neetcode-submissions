class Solution {
public:

    string encode(vector<string>& strs) {
        // String to store everything
        string s;
        // Append length + # (delimiter) + actual string
        for (int i = 0; i < strs.size(); i++) {
            s = s + std::to_string(strs[i].length()) + '#' + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        // Decoded vector
        vector<string> strs;

        int i = 0;

        // loop through string
        while (i < s.length()) {
            // lengh tracker
            int len = 0;
            // loop until we see # (delimiter)
            while (s[i] != '#') {
                // calculate total length
                len = (len*10) + (s[i] - '0');
                i++;
            }
            // push a substr from i + 1 with length "len"
            strs.push_back(s.substr(i + 1, len));
            // Increment i by length + 1 (delimiter)
            i += len + 1;
        }

        return strs;
    }
};
