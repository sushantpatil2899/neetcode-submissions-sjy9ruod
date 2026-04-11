class MinStack {
private:
    stack <int> main_stack;
    stack <int> min_stack; 
public:
    MinStack() {
    }
    
    void push(int val) {
        if (main_stack.empty()) {
            main_stack.push(val);
            min_stack.push(val);
        }
        else {
            main_stack.push(val);
            if (min_stack.top()<val){
                min_stack.push(min_stack.top());
            }
            else{
                min_stack.push(val);
            }
        }
    }
    
    void pop() {
        min_stack.pop();
        return main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
