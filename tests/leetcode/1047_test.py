import pytest

from src.leetcode.s1047 import Solution

dataset = lambda: [
    ("abbaca", "ca"),
    ("aaaaaaaaa", "a"),
]


@pytest.mark.parametrize("s,expected", dataset())
def test(s: str, expected: str):
    result = Solution().removeDuplicates(s)
    assert result == expected
