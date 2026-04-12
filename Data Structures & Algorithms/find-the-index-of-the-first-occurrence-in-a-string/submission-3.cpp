class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;

        int n = 0, h = 0;

        while (n < needle.length() && h < haystack.length()) {
            cout << n <<", " <<h <<endl;
            if (needle[n] == haystack[h]) n++;
            else if (n != 0) {
                h = h -n + 1;
                n=0;
            }
            h++;
        }

        if (n == needle.length()) return h - needle.length();
        else return -1;
    }
};