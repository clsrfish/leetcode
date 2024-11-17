from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.combinationSumBacktrace(candidates, target, 0, list[int]())
        return self.result

    def combinationSumBacktrace(
        self, candidates: list[int], target: int, start: int, arr: list[int]
    ):
        if len(self.result) >= 150:
            return

        if target <= 0:
            return

        for i in range(start, len(candidates)):
            n = candidates[i]
            arr.append(n)
            if n == target:
                self.result.append(list(arr))
            else:
                self.combinationSumBacktrace(candidates, target - n, i, arr)
            arr.pop()
