class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helperFunction(s, t) && helperFunction(t, s);
    }

    bool helperFunction(string s, string t) {
        unordered_map<char, char> char_map;
        for (int i=0; i<s.length();i++) {
            if (char_map.count(s[i]) && char_map[s[i]]!=t[i]) return false;
            char_map[s[i]]=t[i];
        }
        return true;
    }
};