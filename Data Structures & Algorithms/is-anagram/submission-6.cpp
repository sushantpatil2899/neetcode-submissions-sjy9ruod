class Solution {
    
public:
    bool isAnagram(string s, string t) {
        vector<int> hashMap(26, 0);
        for (const char c:s) {
            hashMap[c - 'a']++;
        }

        for (const char c:t) {
            if (hashMap[c - 'a']) hashMap[c - 'a']--;
            else return false;
        }

        for (const int n: hashMap) {
            if (n != 0) return false;
        }

        return true;
    }
};
