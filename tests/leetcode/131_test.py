import pytest

from src.leetcode.s131 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ("aab", [["a", "a", "b"], ["aa", "b"]]),
    ("a", [["a"]]),
]


@pytest.mark.parametrize("s,expected", dataset())
def test(s, expected):
    result = Solution().partition(s)
    assert result == expected
