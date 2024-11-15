import pytest

from src.leetcode.s17 import Solution

dataset = lambda: [
    ("23", ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]),
    ("", []),
    ("2", ["a", "b", "c"]),
]


@pytest.mark.parametrize("digits,expected", dataset())
def test(digits: str, expected: list[str]):
    result = Solution().letterCombinations(digits)
    assert result == expected
