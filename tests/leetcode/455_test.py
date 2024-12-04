import pytest

from src.leetcode.s455 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 3], [1, 1], 1),
    ([1, 2], [1, 2, 3], 2),
]


@pytest.mark.parametrize("g,s,expected", dataset())
def test(g, s, expected):
    result = Solution().findContentChildren(g, s)
    assert result == expected
