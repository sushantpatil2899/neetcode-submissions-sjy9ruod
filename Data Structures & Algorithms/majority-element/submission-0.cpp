class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_map;
        int out;
        int n = nums.size();
        for (int &i: nums) {
            if (!num_map.count(i)) num_map[i] = 0;
            num_map[i] = num_map[i] + 1;
            if (num_map[i]>(n/2)) {
                out =  i;
                break;
            }
        }
        
        return out;
    }
};