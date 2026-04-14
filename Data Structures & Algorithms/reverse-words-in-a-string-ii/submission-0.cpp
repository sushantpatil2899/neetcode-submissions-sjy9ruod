class Solution {
private:
    void reverseString(vector<char>& s, int l, int r) {
        while (l < r) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
    }

public:
    void reverseWords(vector<char>& s) {
        reverseString(s, 0, s.size()-1);
        int l = 0, r = 0;

        while (l < s.size() && r <s.size()) {
            if (s[r] == ' ') {
                reverseString(s, l, r-1);
                l = r+1;
            }
            r++;
        }

        reverseString(s, l, r-1);
    }
};
