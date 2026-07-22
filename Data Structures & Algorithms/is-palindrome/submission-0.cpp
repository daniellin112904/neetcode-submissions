class Solution {
public:
    bool isPalindrome(string s) {
        // pointer to beginning and ending chars
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // move to next if not alnum
            while (!isalnum(s[left]) && left < right)
                left++;
            while (!isalnum(s[right]) && left < right)
                right--;
            // if not equal, return false. tolower to convert chars to lowercase
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
