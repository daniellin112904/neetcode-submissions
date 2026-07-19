class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map <char, int> sFreq;
        std::unordered_map <char, int> tFreq;

        for (int i = 0; i < s.length(); i++) {
            sFreq[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            tFreq[t[i]]++;
        }

        return sFreq == tFreq;
    }
};
