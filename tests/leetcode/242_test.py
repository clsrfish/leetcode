import pytest

from src.leetcode.s242 import Solution
from src.model import ListNode

dataset = lambda: [
    ("anagram", "nagaram", True),
    ("rat", "car", False),
]


@pytest.mark.parametrize("s,t,expected", dataset())
def test(s: str, t: str, expected: bool):
    result = Solution().isAnagram(s, t)
    assert result == expected
