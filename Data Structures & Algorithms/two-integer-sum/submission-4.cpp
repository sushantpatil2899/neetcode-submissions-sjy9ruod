class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>arr;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                arr.push_back(mp[target-nums[i]]);
                arr.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }

        return arr;
    }
};
