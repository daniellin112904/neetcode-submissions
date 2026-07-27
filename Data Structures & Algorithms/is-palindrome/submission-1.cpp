class Solution {
public:
    bool isPalindrome(string s) {
        // Pointer to beginning and end of string
        int left = 0;
        int right = s.length() - 1;

        // loop until they meet or cross
        while (left < right) {
            // if its not alnum, skip to next
            while(!isalnum(s[left]) && left < right)
                left++;
            while(!isalnum(s[right]) && left < right)
                right--;
            
            // return false if no the same char (check lowercase)
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};
