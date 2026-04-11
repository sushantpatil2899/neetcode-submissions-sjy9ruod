class Solution {
    unordered_map<int,int> sum_map;
public:
    int rob(vector<int>& nums) {
        int max_sum = 0;
        for (int i=0; i<=1; i++) {
            max_sum = max(max_sum,recursiveSum(i, nums));
        }
        return max_sum;
    }

    int recursiveSum(int index, vector<int>& nums) {
        if (index>=nums.size()) return 0;
        if (sum_map.count(index)) return sum_map[index];
        int sum = 0;
        for (int j = index+2; j<nums.size(); j++) {
            sum = max(sum, recursiveSum(j, nums));
        }
        sum_map[index] = sum + nums[index];
        return sum_map[index];
    }
};