class MinStack {
    private Stack<Integer> main_stack;
    private Stack<Integer> min_stack;
    public MinStack() {
        main_stack = new Stack<>();
        min_stack = new Stack<>();
    }
    
    public void push(int val) {
        main_stack.push(val);
        if (min_stack.isEmpty()) {
            min_stack.push(val);
        }
        else {
            min_stack.push(Math.min(val, min_stack.peek()));
        }
    }
    
    public void pop() {
        min_stack.pop();
        main_stack.pop();
    }
    
    public int top() {
        return main_stack.peek();
    }
    
    public int getMin() {
        return min_stack.peek();
    }
}
