class Solution {
    unordered_set<int> u;
public:
    bool hasDuplicate(vector<int>& nums) {
        for (const int n: nums) {
            if (u.count(n)) return true;
            u.insert(n);
        }

        return false;
    }
};