import pytest

from src.leetcode.s90 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 2], [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]),
    ([0], [[], [0]]),
]


@pytest.mark.skip()
@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().subsetsWithDup(nums)
    assert result == expected
