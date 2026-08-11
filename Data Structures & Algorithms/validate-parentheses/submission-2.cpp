class Solution {
public:
    bool isValid(string s) {
        // Stack to hold opening brackets
        stack<char> opening;
        for (char c: s) {
            // Push if opening
            if (c == '[' || c == '(' || c == '{')
                opening.push(c);
            else {
                // Check if stack is empty (no opening)
                if (opening.empty())
                    return false;
                // Pop if brackets match
                if (c == ')' && opening.top() == '(')
                    opening.pop();
                else if (c == ']' && opening.top() == '[')
                    opening.pop();
                else if (c == '}' && opening.top() == '{')
                    opening.pop();
                // False if brackets don't match
                else return false;
            }
        }
        // Check for remaining opening brackets
        return opening.empty();
    }
};
