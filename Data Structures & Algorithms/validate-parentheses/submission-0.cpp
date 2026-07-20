class Solution {
public:
    bool isValid(string s) {
        std::stack<char> opening;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                opening.push(s[i]);
            else {
                if (opening.empty())
                    return false;
                if (s[i] == ')' && opening.top() == '(')
                    opening.pop();
                else if (s[i] == ']' && opening.top() == '[')
                    opening.pop();
                else if (s[i] == '}' && opening.top() == '{')
                    opening.pop();
                else return false;
            }
        }
        return opening.empty();
    }
};
