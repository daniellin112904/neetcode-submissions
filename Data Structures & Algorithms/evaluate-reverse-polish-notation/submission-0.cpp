class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Stack to hold char (string)
        stack<int> token;
        
        for (string c: tokens) {
            // If its an operand, take previous 2 ints
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int num1 = token.top();
                token.pop();
                int num2 = token.top();
                token.pop();

                // Do operand
                if (c == "+") token.push(num2 + num1);
                else if (c == "-") token.push(num2 - num1);
                else if (c == "*") token.push(num2 * num1);
                else token.push(num2 / num1);
            } else token.push(stoi(c));
        }
        return token.top();
    }
};
