import pytest

from src.leetcode.s1002 import Solution
from src.model import ListNode

dataset = lambda: [
    (["bella", "label", "roller"], ["e", "l", "l"]),
    (["cool", "lock", "cook"], ["c", "o"]),
]


@pytest.mark.parametrize("words,expected", dataset())
def test(words, expected):
    result = Solution().commonChars(words)
    assert sorted(result) == sorted(expected)
