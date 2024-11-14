from typing import List


class Solution:
    def __init__(self) -> None:
        self.result: list[list[int]] = []

    def combine(self, n: int, k: int) -> List[List[int]]:
        self.combinBacktrace(1, n, k, [])
        return self.result

    def combinBacktrace(self, start: int, end: int, k: int, arr: list[int]):
        if k == 0:
            self.result.append(list(arr))
            return
        for i in range(start, end - k + 2):
            arr.append(i)
            self.combinBacktrace(i + 1, end, k - 1, arr)
            arr.pop()
