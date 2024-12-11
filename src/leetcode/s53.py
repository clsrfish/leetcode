from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        fi_1 = max_sum
        for i in range(1, len(nums)):
            if fi_1 <= 0:
                max_i = nums[i]
            else:
                max_i = nums[i] + fi_1
            fi_1 = max_i
            max_sum = max(max_sum, max_i)

        return max_sum
