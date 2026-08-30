class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Set to store chars in our substr
        unordered_set<int> charSet;
        // Left pointer at one, right pointer is i in for loop
        int left = 0;
        int result = 0;

        for(int i = 0; i < s.length(); i++) {
            // If current char is in set, remove and move pointer until it's not
            while (charSet.contains(s[i])) {
                charSet.erase(s[left]);
                left++;
            }
            // Add current char to set
            charSet.insert(s[i]);
            // Compare max to current length (right(i) - left + 1)
            result = max(result, i - left + 1);
        }
        return result;
    }
};
