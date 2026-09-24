class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Stack to hold temperature indices
        stack<int> temp;
        // Vector to hold result with same size (default value 0)
        vector<int> result(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            // Stack not empty + current temp > temp at top
            while (!(temp.empty()) && 
            temperatures[i] > temperatures[temp.top()]) {
                // Store diff in result and pop
                result[temp.top()] = i - temp.top();
                temp.pop();
            }
            // Push index to stack if smallest temp
            temp.push(i);
        }
        return result;
    }
};
