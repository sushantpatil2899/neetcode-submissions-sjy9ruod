class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, c = 0, s = source.length(), t = target.length();
        
        while (j < t) {
            if (source[i] == target[j]) {
                i++;
                j++;
            }
            else {
                int start_i = i;
                i++;
                while (i<s && source[i] != target[j]) i++;
                if (i == s) {
                    if (start_i == 0) return -1;
                    else {
                        c++;
                        i = 0;
                    }
                }
                else {
                    i++;
                    j++;
                }
            }
            if (i == s) {
                c++;
                i = 0;
            }
        }
        if (i!= s && i!= 0) c++;
        return c;

    }
};
