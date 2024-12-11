import pytest
from src.leetcode.s53 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([-2, 1, -3, 4, -1, 2, 1, -5, 4], 6),
    ([1], 1),
    ([5, 4, -1, 7, 8], 23),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().maxSubArray(nums)
    assert result == expected
