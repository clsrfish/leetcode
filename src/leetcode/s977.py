from typing import List, Optional

from src.model import ListNode


class Solution:

    def sortedSquares(self, nums: List[int]) -> List[int]:
        result = list[int]()
        left = 0
        right = len(nums) - 1

        while left < right:
            sum = nums[left] + nums[right]
            if sum < 0:
                result.append(nums[left] ** 2)
                left += 1
            elif sum > 0:
                result.append(nums[right] ** 2)
                right -= 1
            else:
                result.extend([nums[right] ** 2] * 2)
                right -= 1
                left += 1
        if len(result) != len(nums):
            result.append(nums[right] ** 2)
        return list(reversed(result))
