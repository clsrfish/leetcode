from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[str]]()

    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [["."] * n for _ in range(0, n)]
        self._solveNQueens(n, 0, board)
        return self.result

    def _solveNQueens(self, n: int, j: int, board: list[list[str]]):
        if j == n:
            self.result.append(["".join(row) for row in board])
            return

        for i in range(0, n):
            if not self._isValidPos(n, i, j, board):
                continue

            board[j][i] = "Q"
            self._solveNQueens(n, j + 1, board)
            board[j][i] = "."

    def _isValidPos(self, n: int, i: int, j: int, board: list[list[int]]) -> bool:
        for d in range(1, j + 1):
            if board[j - d][i] == "Q":
                return False
        for d in range(1, max(i, j) + 1):
            if j - d >= 0 and i - d >= 0 and board[j - d][i - d] == "Q":
                return False
            if j - d >= 0 and i + d < n and board[j - d][i + d] == "Q":
                return False

        return True
