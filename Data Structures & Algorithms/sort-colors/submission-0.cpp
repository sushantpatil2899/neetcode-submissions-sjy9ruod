class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for (int i=0; i<nums.size(); i++) {
            counts[nums[i]]++;
        }

        int i = 0;
        for (int n=0; n<counts.size(); n++) {
            for (int j = 0; j<counts[n]; j++) {
                nums[i] = n;
                i++;
            }
        }
    }
};