import pytest

from src.leetcode.s112 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1], 22, True),
    ([1, 2, 3], 5, False),
    ([], 0, False),
    ([1, 2], 1, False),
]


@pytest.mark.parametrize("nums,target,expected", dataset())
def test(nums, target, expected):
    root = TreeNode.fromList(nums)
    result = Solution().hasPathSum(root, target)
    assert result == expected
