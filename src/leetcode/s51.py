from typing import List


class Solution:
    def __init__(self) -> None:
        self.result = list[list[str]]()

    def solveNQueens(self, n: int) -> List[List[str]]:
        queens = list[int]()
        self._solveNQueens(n, 0, queens)
        return self.result

    def _solveNQueens(self, n: int, j: int, queens: list[int]):
        if j == n:
            board = ["." * x + "Q" + "." * (n - x - 1) for x in queens]
            self.result.append(board)
            return

        for i in range(0, n):
            if not self._isValidPos(i, j, queens):
                continue

            queens.append(i)
            self._solveNQueens(n, j + 1, queens)
            queens.pop()

    def _isValidPos(self, i: int, j: int, queens: list[int]) -> bool:
        for y in range(0, len(queens)):
            x = queens[y]
            if i == x:
                return False
            if abs(i - x) == abs(j - y):
                return False

        return True
