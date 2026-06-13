class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preMul(nums.size()), postMul(nums.size());
        preMul[0] = 1;
        postMul[nums.size()-1] = 1;

        for (int i = 1; i<nums.size(); i++) {
            preMul[i] = preMul[i-1] * nums[i-1];
        }

        for (int i = nums.size()-2; i>=0; i--) {
            postMul[i] = postMul[i+1] * nums[i+1];
        }

        vector<int> result(nums.size());
        for (int i = 0; i<nums.size(); i++) {
            result[i] = preMul[i] * postMul[i];
        }

        return result;
    }
};
