from typing import List, Optional

from src.model import ListNode


class Solution:

    def sortedSquares(self, nums: List[int]) -> List[int]:
        result = list[int]()
        left = 0
        right = len(nums) - 1
        while left < len(nums) and nums[left] < 0:
            left += 1
        while right >= 0 and nums[right] >= 0:
            right -= 1
        left -= 1
        right += 1

        while left >= 0 and right < len(nums):

            if nums[left] + nums[right] < 0:
                result.append(nums[right] ** 2)
                right += 1
            elif nums[left] + nums[right] > 0:
                result.append(nums[left] ** 2)
                left -= 1
            else:
                result.extend([nums[right] ** 2] * 2)
                right += 1
                left -= 1

        while right < len(nums):
            result.append(nums[right] ** 2)
            right += 1
        while left >= 0:
            result.append(nums[left] ** 2)
            left -= 1
        return result
