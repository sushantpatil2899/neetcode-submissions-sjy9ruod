class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (!(m ==n || m==n+1 || m==n-1) || (m==0 && n==0)) return false;
        if (s==t) return false;
        int i = 0;
        int j = 0;
        int c = 1;
        while (i < n) {
            if (j == m) return true;
            if (t[i] == s[j]) {
                j++;
                i++;
            }
            else if (c) {
                c--;
                if (m == n-1) i++;
                else if (m == n+1) j++;
                else {
                    i++;
                    j++;
                }
            }
            else return false;
        }

        return i==n;
    }
};
