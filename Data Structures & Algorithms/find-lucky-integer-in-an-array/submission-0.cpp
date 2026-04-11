class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> arrMap;
        int luckyInteger = -1;

        for (int a: arr) {
            if (!arrMap.count(a)) arrMap[a] = 0;
            arrMap[a] += 1;
        }

        for (pair p: arrMap) {
            if (p.first==p.second) {
                luckyInteger = max(p.first, luckyInteger);
            }
        }

        return luckyInteger;
    }
};