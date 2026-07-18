class Solution {
public:

    string encode(vector<string>& strs) {
        // Store eveything in one encoded string
        string s = "";
        // Store length of string + delimiter then actual string
        for (int i = 0; i < strs.size(); i++) {
            s = s + std::to_string (strs[i].length()) + '#' + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int len = 0;
            // If we haven't reach delimiter (calculating length size)
            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }
            // Push a substr of size len
            strs.push_back(s.substr(i + 1, len));
            // Jump i to after string
            i += (len + 1);
        }
        return strs;
    }
};
