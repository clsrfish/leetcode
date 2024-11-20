from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self._findDfs(nums, 0, list[int]())
        return self.result

    def _findDfs(self, nums: list[int], pos: int, seq: list[int]):
        if pos == len(nums):
            if len(seq) >= 2:
                self.result.append(seq[:])
            return

        if len(seq) == 0 or nums[pos] >= seq[-1]:
            seq.append(nums[pos])
            self._findDfs(nums, pos + 1, seq)
            seq.pop()

        if len(seq) == 0 or nums[pos] != seq[-1]:
            self._findDfs(nums, pos + 1, seq)
