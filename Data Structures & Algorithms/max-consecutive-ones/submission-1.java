class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int max_count = 0;
        for (int i = 0; i<nums.length; i++) {
            System.out.println("i : "+i+", count: "+count+", max_count: "+max_count);
            if (nums[i]==0) {
                max_count = Math.max(count, max_count);
                count = 0;
            }
            else {
                count++;
            }
        }

        return Math.max(count, max_count);
    }
}