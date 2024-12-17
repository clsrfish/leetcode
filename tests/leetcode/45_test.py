import pytest

from src.leetcode.s45 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([2, 3, 1, 1, 4], 2),
    ([2, 3, 0, 1, 4], 2),
]


@pytest.mark.skip
@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().jump(nums)
    assert result == expected
