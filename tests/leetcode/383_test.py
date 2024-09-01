import pytest

from src.leetcode.s383 import Solution

dataset = lambda: [
    ("a", "b", False),
    ("aa", "ab", False),
    ("aa", "aab", True),
]


@pytest.mark.parametrize("ransomNote,magazine,expected", dataset())
def test(ransomNote, magazine, expected):
    result = Solution().canConstruct(ransomNote, magazine)
    assert result == expected
