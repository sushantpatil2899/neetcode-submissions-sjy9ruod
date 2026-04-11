class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> close_to_open = new HashMap<>();
        close_to_open.put(')', '(');
        close_to_open.put('}', '{');
        close_to_open.put(']', '[');
        for (char c: s.toCharArray()) {
            if (close_to_open.containsKey(c)) {
                if (!stack.isEmpty() && stack.peek()==close_to_open.get(c)) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
