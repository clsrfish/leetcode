import logging
from typing import List, Optional

from src.model import ListNode


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        if k == 0:
            return

        rotated = 0
        curIndex = 0
        tmpValue = None
        while rotated < len(nums):
            if tmpValue is not None:
                rotated += 1
            curValue = nums[curIndex]
            nums[curIndex] = tmpValue
            tmpValue = curValue

            if tmpValue is None:
                curIndex = curIndex + 1
            else:
                curIndex = (curIndex + k) % len(nums)


class SolutionSlice:
    def reverse(self, nums: list[int], start: int, end: int) -> None:
        while start < end:
            tmp = nums[start]
            nums[start] = nums[end]
            nums[end] = tmp
            start += 1
            end -= 1

    def rotate(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        if k == 0:
            return

        nums.reverse()
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, len(nums) - 1)
