import pytest

from src.leetcode.s216 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    (3, 7, [[1, 2, 4]]),
    (3, 9, [[1, 2, 6], [1, 3, 5], [2, 3, 4]]),
    (4, 1, []),
]


@pytest.mark.parametrize("k,n,expected", dataset())
def test(k: int, n: int, expected: list[list[int]]):
    result = Solution().combinationSum3(k, n)
    assert result == expected
