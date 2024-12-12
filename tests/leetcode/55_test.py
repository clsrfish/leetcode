import pytest

from src.leetcode.s55 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([2, 3, 1, 1, 4], True),
    ([3, 2, 1, 0, 4], False),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().canJump(nums)
    assert result == expected
