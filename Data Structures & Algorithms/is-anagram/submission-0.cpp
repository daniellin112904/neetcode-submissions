class Solution {
public:
    bool isAnagram(string s, string t) {
        // hashtable to hold frequency of chars in both string
        std::unordered_map <char, int> sFreq;
        std::unordered_map <char, int> tFreq;

        if (s.length() != t.length())
            return false;
        
        // add frequency in s
        for (int i = 0; i < s.length(); i++) {
            if (sFreq.contains(s[i]))
                sFreq[s[i]] += 1;
            else sFreq[s[i]] = 1;
        }
        
        // add frequency in t
        for (int i = 0; i < t.length(); i++) {
            if (tFreq.contains(t[i]))
                tFreq[t[i]] += 1;
            else tFreq[t[i]] = 1;
        }

        // check if they match
        return sFreq == tFreq;
    }
};
