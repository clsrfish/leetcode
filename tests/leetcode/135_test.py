import pytest

from src.leetcode.s135 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 0, 2], 5),
    ([1, 2, 2], 4),
    ([1, 3, 4, 5, 2], 11),
]


@pytest.mark.parametrize("ratings,expected", dataset())
def test(ratings, expected):
    result = Solution().candy(ratings)
    assert result == expected
