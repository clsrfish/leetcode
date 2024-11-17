from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.combinationSum2Backtrace(sorted(candidates), target, 0, list[int]())
        return self.result

    def combinationSum2Backtrace(
        self, candidates: list[int], target: int, start: int, arr: list[int]
    ):
        if target <= 0:
            return
        for i in range(start, len(candidates)):
            n = candidates[i]
            if i > start and n == candidates[i - 1]:
                continue
            arr.append(n)
            if n == target:
                self.result.append(arr[:])
            elif n <= target // 2:
                self.combinationSum2Backtrace(candidates, target - n, i + 1, arr)

            arr.pop()
