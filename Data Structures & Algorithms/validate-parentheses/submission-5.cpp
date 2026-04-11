class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> close_to_open = {{')','('}, {'}','{'}, {']','['}};

        for (char c:s) {
            if (close_to_open.count(c)) {
                if (!stack.empty() && stack.top()==close_to_open[c]) {
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
        return stack.empty();
    }
};
