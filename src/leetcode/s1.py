from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = dict[int, int]()
        for i in range(0, len(nums)):
            diff = target - nums[i]
            if diff in m:
                return [m[diff], i]
            m[nums[i]] = i
        return []
