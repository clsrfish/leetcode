import pytest

from src.leetcode.s51 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    (4, [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]),
    (1, [["Q"]]),
]


@pytest.mark.parametrize("n,expected", dataset())
def test(n, expected):
    result = Solution().solveNQueens(n)
    assert result == expected
