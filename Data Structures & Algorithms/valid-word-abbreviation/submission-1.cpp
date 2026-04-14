class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int m = word.length();
        int n = abbr.length();

        while (i < m && j < n) {
            if (abbr[j] == '0') return false;
            if (isalpha(abbr[j])) {
                if (abbr[j] == word[i]) {
                    i++;
                    j++;
                }
                else return false;
            }
            else {
                int subLen = 0;
                while (j < n && isdigit(abbr[j])) {
                    subLen = subLen*10 + (abbr[j] - '0');
                    j++;
                }
                i+=subLen;
            }
        }

        if (i==m && j==n) return true;
        return false;
    }
};