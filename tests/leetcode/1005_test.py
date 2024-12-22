import pytest

from src.leetcode.s1005 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([4, 2, 3], 1, 5),
    ([3, -1, 0, 2], 3, 6),
    ([2, -3, -1, 5, -4], 2, 13),
]


@pytest.mark.parametrize("nums,k,expected", dataset())
def test(nums, k, expected):
    result = Solution().largestSumAfterKNegations(nums, k)
    assert result == expected
