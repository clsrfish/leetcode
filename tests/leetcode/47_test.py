import pytest

from src.leetcode.s47 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 1, 2], [[1, 1, 2], [1, 2, 1], [2, 1, 1]]),
    ([1, 2, 3], [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().permuteUnique(nums)
    assert sorted(result) == sorted(expected)
