class MinStack {
public:
    // Stack memeber variables
    stack<int> mainSt;
    stack<int> minSt;

    MinStack() {
        // C++ auto ititializes stacks
    }
    
    void push(int val) {
        // Push to main stack
        mainSt.push(val);
        // Push to min if it's empty (no minimum)
        if (minSt.empty()) minSt.push(val);
        // Not empty => check if less than current top, push lower
        else minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        mainSt.pop();
        minSt.pop();
    }
    
    int top() {
        return mainSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
