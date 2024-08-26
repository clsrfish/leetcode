from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minLen = len(nums) + 1
        left = 0
        right = 0
        currentSum = 0
        while right < len(nums):
            currentSum += nums[right]
            while currentSum >= target:
                minLen = min(minLen, right - left + 1)
                currentSum -= nums[left]
                left += 1
            right += 1

        return 0 if minLen == len(nums) + 1 else minLen
