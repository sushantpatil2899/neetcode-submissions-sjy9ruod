class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        count_map = {}
        for i in range(0, len(nums)):
            if (target - nums[i]) in count_map.keys():
                return [count_map[target - nums[i]], i]
            count_map[nums[i]] = i
            