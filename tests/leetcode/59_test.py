import pytest

from src.leetcode.s59 import Solution
from src.model import ListNode

dataset = lambda: [
    (3, [[1, 2, 3], [8, 9, 4], [7, 6, 5]]),
    (1, [[1]]),
]


@pytest.mark.parametrize("n,expected", dataset())
def test(n, expected):
    result = Solution().generateMatrix(n)
    assert result == expected
