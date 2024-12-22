from typing import List


class Solution:

    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        i = 0
        for _ in range(0, k):
            nums[i] = -nums[i]

            if i + 1 < len(nums) and nums[i] > nums[i + 1]:
                i += 1

        return sum(nums)
