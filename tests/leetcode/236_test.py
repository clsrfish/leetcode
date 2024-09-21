import pytest

from src.leetcode.s236 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([3, 5, 1, 6, 2, 0, 8, None, None, 7, 4], 5, 1, 3),
    ([3, 5, 1, 6, 2, 0, 8, None, None, 7, 4], 5, 4, 5),
    ([1, 2], 1, 2, 1),
]


@pytest.mark.parametrize("nums,p,q,expected", dataset())
def test(nums, p, q, expected):
    root = TreeNode.fromList(nums)
    result = Solution().lowestCommonAncestor(
        root, TreeNode.findNode(root, p), TreeNode.findNode(root, q)
    )
    assert result.val == expected
