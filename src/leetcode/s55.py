from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:

    def __init__(self):
        self.cantJumPos = set[int]()

    def canJump(self, nums: List[int]) -> bool:
        return self._canJump(nums, 0)

    def _canJump(self, nums: list[int], pos: int) -> bool:
        if pos in self.cantJumPos:
            return False
        if pos >= len(nums) - 1:
            return True
        maxStep = nums[pos]

        for step in reversed(range(1, maxStep + 1)):
            if self._canJump(nums, pos + step):
                return True
        self.cantJumPos.add(pos)
        return False
