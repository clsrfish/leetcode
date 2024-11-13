import pytest

from src.leetcode.s669 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 0, 2], 1, 2, [1, None, 2]),
    ([3, 0, 4, None, 2, None, None, 1], 1, 3, [3, 2, None, 1]),
]


@pytest.mark.parametrize("nums,low,high,expected", dataset())
def test(nums, low, high, expected):
    root = TreeNode.fromList(nums)
    result = Solution().trimBST(root, low, high)
    assert TreeNode.toList(result) == expected
