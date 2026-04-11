class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False;

        s_dict = {}
        t_dict = {}

        for i in range(0, len(s)):
            s_dict[s[i]] = (s_dict[s[i]] if s[i] in s_dict.keys() else 0) + 1
            t_dict[t[i]] = (t_dict[t[i]] if t[i] in t_dict.keys() else 0) + 1
        
        return s_dict==t_dict