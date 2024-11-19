from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.subsetsBacktrace(nums, 0, list[int]())
        return self.result

    def subsetsBacktrace(self, nums: list[int], pos: int, subset: list[int]):
        if pos == len(nums):
            self.result.append(subset[:])
            return

        subset.append(nums[pos])
        self.subsetsBacktrace(nums, pos + 1, subset)
        subset.pop()

        self.subsetsBacktrace(nums, pos + 1, subset)
