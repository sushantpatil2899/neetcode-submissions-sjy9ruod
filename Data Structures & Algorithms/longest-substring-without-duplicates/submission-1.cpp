class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxLen = 0;
        unordered_set<char> seqChar;

        while (r < s.length()) {
            while (seqChar.find(s[r])!=seqChar.end()) seqChar.erase(s[l++]);
            seqChar.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
