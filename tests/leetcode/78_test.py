import pytest

from src.leetcode.s78 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 3], [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]),
    ([0], [[], [0]]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().subsets(nums)
    assert sorted(result) == sorted(expected)
