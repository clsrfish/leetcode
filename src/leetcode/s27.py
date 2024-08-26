from typing import List, Optional

from src.model import ListNode


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0
        right = len(nums) - 1
        while True:
            while left < right and nums[left] != val:
                left += 1

            while left < right and nums[right] == val:
                right -= 1
            if left >= right:
                break

            nums[left], nums[right] = nums[right], nums[left]

            left += 1
            right -= 1

        while left < len(nums) and nums[left] != val:
            left += 1

        return left
