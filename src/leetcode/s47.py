from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self._permuteBacktrace(sorted(nums), list[int]())
        return self.result

    def _permuteBacktrace(self, nums: list[int], arr: list[int]):
        if len(arr) == len(nums):
            self.result.append([nums[i] for i in arr])
            return

        last = None
        for i in range(0, len(nums)):
            if i in arr:
                continue
            n = nums[i]
            if n == last:
                continue
            last = n
            arr.append(i)
            self._permuteBacktrace(nums, arr)
            arr.pop()
