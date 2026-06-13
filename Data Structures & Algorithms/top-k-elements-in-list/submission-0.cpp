class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hp;
        vector<vector<int>> freqMap(nums.size() + 1);

        for (const int n: nums) {
            hp[n] = hp[n] + 1;
        }

        for (const auto& p: hp) {
            freqMap[p.second].push_back(p.first);
        }

        vector<int> result;

        for (int i = nums.size(); i > 0; i-- ) {
            for (int n: freqMap[i]) {
                result.push_back(n);
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};
