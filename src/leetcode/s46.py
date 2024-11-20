from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def permute(self, nums: List[int]) -> List[List[int]]:
        self._permuteBacktrace(nums, list[int]())
        return self.result

    def _permuteBacktrace(self, nums: list[int], picked: list[int]):
        if len(picked) == len(nums):
            self.result.append(picked[:])
            return

        for n in nums:
            if n in picked:
                continue
            picked.append(n)
            self._permuteBacktrace(nums, picked)
            picked.pop()
