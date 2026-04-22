class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        unordered_map<char, int> count;

        while (r < s.length()) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            while ((r-l+1) - maxFreq > k) count[s[l++]]--;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
