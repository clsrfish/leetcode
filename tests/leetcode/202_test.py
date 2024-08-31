import pytest

from src.leetcode.s202 import Solution
from src.model import ListNode

dataset = lambda: [
    (19, True),
    (2, False),
]


@pytest.mark.parametrize("n,expected", dataset())
def test(n: int, expected: bool):
    result = Solution().isHappy(n)
    assert result == expected
