import pytest

from src.leetcode.s20 import Solution
from src.model import ListNode

dataset = lambda: [
    ("()", True),
    ("()[]{}", True),
    ("(]", False),
    ("([])", True),
]


@pytest.mark.parametrize("s,expected", dataset())
def test(s: str, expected: bool):
    result = Solution().isValid(s)
    assert result == expected
