import pytest

from src.leetcode.s235 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5], 2, 8, 6),
    ([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5], 2, 4, 2),
    ([2, 1], 2, 1, 2),
]


@pytest.mark.parametrize("nums,p,q,ancestor", dataset())
def test(nums: list[int], p: int, q: int, ancestor: int):
    root = TreeNode.fromList(nums)
    result = Solution().lowestCommonAncestor(
        root, TreeNode.findNode(root, p), TreeNode.findNode(root, q)
    )
    assert result.val == ancestor
