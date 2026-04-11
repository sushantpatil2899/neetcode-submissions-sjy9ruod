class Solution {
    public int[] getConcatenation(int[] nums) {
        int nums_length = nums.length;
        int[] concatenated_nums = new int[2*nums_length];
        for (int i=0; i<nums_length; i++){
            concatenated_nums[i] = nums[i];
            concatenated_nums[i+nums_length] = nums[i];
        }
        return concatenated_nums;
    }
}