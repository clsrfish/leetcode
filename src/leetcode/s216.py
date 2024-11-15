from typing import List


class Solution:
    def __init__(self) -> None:
        self.result = list[list[int]]()

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.combinationBacktrace(k, n, 1, list[int]())
        return self.result

    def combinationBacktrace(self, k: int, n: int, start: int, arr: list[int]):
        if k == 0:
            return
        currentSum = sum(arr)
        for i in range(start, 10):
            if currentSum + i > n:
                break
            if currentSum + i == n and k == 1:
                arr.append(i)
                self.result.append(list(arr))
                arr.pop()
                break
            if currentSum + i < n:
                arr.append(i)
                self.combinationBacktrace(k - 1, n, i + 1, arr)
                arr.pop()
                continue
            break
