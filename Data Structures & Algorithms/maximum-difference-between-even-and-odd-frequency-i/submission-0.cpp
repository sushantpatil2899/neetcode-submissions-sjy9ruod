class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> s_map;
        for (char& c:s) {
            if (!s_map.count(c)) s_map[c] = 0;
            s_map[c] += 1;
        }
        int max_even = 1000000;
        int max_odd = 0;
        for (pair p: s_map) {
            if (p.second%2==0) {
                max_even = min(max_even, p.second);
            }
            else {
                max_odd = max(max_odd, p.second);
            }
        }

        return max_odd -max_even;
    }
};