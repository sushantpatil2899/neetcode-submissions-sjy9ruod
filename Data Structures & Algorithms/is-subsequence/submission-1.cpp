class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_length = s.length(), t_length = t.length();

        if (s_length > t_length) return false;

        int i = 0, j = 0;

        while (i < s_length && j < t_length) {
            if (s[i] == t[j]) i++;
            j++;
        }

        if (i == s_length) return true;
        return false;
    }
};