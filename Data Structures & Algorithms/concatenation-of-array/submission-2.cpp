class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> concatenated_nums = nums;
        concatenated_nums.insert(concatenated_nums.end(), nums.begin(), nums.end());
        return concatenated_nums;
    }
};