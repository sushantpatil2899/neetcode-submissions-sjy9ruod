class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> count_map;
        vector<int> output;
        for (int i=0; i<nums.size(); i++) {
            if (count_map.count(target - nums[i])) {
                output.push_back(count_map[target - nums[i]]);
                output.push_back(i);
                return output;
            }
            count_map.insert({nums[i],i});
        }
    }
};
