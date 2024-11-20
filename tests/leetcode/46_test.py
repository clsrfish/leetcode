import pytest

from src.leetcode.s46 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 3], [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]),
    ([0, 1], [[0, 1], [1, 0]]),
    ([1], [[1]]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().permute(nums)
    assert sorted(result) == sorted(expected)
