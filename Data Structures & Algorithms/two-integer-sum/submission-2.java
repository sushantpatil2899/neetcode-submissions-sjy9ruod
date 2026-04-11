class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> count_map = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            if (count_map.containsKey(target-nums[i])) {
                return new int[] {count_map.get(target-nums[i]), i};
            }
            count_map.put(nums[i], i);
        }

        return new int[] {};
    }
}
