class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        char c = chars[0];
        int count = 1;

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == c) count++;
            else {
                chars[index++] = c;
                if (count > 1) {
                    string s = to_string(count);
                    for (char c: s) {
                        chars[index++] = c;
                    }
                }
                c = chars[i];
                count = 1;
            }
        }
        chars[index++] = c;
        if (count > 1) {
            string s = to_string(count);
            for (char c: s) {
                chars[index++] = c;
            }
        }

        return index;
    }
};