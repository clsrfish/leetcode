from typing import List


class Solution:

    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        i = 0
        while k > 0:
            k -= 1
            nums[i] = -nums[i]

            if i + 1 < len(nums) and nums[i] > nums[i + 1]:
                i += 1

            if nums[i] >= 0:
                k = k % 2
        return sum(nums)
